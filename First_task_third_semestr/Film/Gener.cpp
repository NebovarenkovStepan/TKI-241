#include "Gener.h"

namespace film
{
    void Genres::add_genre(const string& genre)
    {
        shared_ptr<string> genre_ptr = make_shared<string>(genre);

        genres.push_back(weak_ptr<string>(genre_ptr));
    }

    Genres::Genres() : genres(), movie(){}

    Genres::Genres(vector<weak_ptr<string>> geners, shared_ptr<Movie> movie) : genres(genres), movie(move(movie))
    {
    }

    string Genres::get_genres() const
    {
        stringstream buffer;
        buffer << "Genres: \n"; 

        for (size_t i = 0; i < genres.size(); ++i)
        {
            if (auto genre_ptr = genres[i].lock()) 
            {
                buffer << *genre_ptr;
                if (i < genres.size() - 1)
                {
                    buffer << ", ";
                }
            }
        }
        buffer << ".\n";
        return buffer.str();
    }
}