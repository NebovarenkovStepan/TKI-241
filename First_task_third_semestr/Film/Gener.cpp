#include "Gener.h"

namespace film
{
    void Genre::add_movie(shared_ptr<Movie> movie) 
    {
        this->movies.push_back(movie.get());
        movie->get_genres().push_back(shared_from_this());
    }

    Genre::Genre(string genre) : genre(genre){}

    shared_ptr<Genre> Genre::create_genre(string genre)
    {
        return make_shared<Genre>(Genre{ genre });
    }

    Genre::Genre(const string& geners, shared_ptr<Movie> movie) : genre(genre), movie(movie)
    {
    }

    string Genre::get_genre() const
    {
        stringstream buffer;
        buffer << "Genre: \n";
        buffer << genre;
        buffer << ".\n";
        return buffer.str();
    }
    bool operator==(const Genre& lha, const Genre& rha)
    {
        return lha.get_genre() == rha.get_genre();
    }
}