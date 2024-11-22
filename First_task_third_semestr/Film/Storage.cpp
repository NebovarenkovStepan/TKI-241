#include "Storage.h"

using namespace std;

namespace film
{
    Storage::Storage(const string& name) : name(name){}

    shared_ptr<Storage> Storage::create_storage(const string& name)
    {
        return make_shared<Storage>(Storage{ name });
    }


    void Storage::add_movie(shared_ptr<Movie> movie)
    {
        this->movies.push_back(movie.get());
        movie.get()-> storage = shared_from_this();
    }

    void Storage::remove_movie(shared_ptr<Movie> movie)
    {
        this->movies.erase(std::remove(this->movies.begin(), this->movies.end(), movie.get()), this->movies.end());
        movie.get()-> storage = nullptr;
    }

    string Storage::search_by_title(const string& title)
    {
        for (const auto& movie : movies)
        {
            if (movie->get_title() == title)
            {
                return movie->to_string();
            }
        }
        return "There are no movie with this title";
    }

    vector<Movie> Storage::search_by_genre(const string& genre)
    {
        vector<Movie> result;
        for (const auto& movie : movies)
        {
            auto genres = movie->get_genres();
            if (find(genres.begin(), genres.end(), genres) != genres.end())
            {
                result.push_back(*movie);
            }
        }
        return result;
    }

    vector<Movie> Storage::search_by_director(const string& director)
    {
        vector<Movie> result;
        for (const auto& movie : movies)
        {
            auto directors = movie->get_directors();
            if (find(directors.begin(), directors.end(), director) != directors.end())
            {
                result.push_back(*movie);
            }
        }
        return result;
    }

    vector<Movie> Storage::search_by_actor(const string& actor)
    {
        vector<Movie> result;
        for (const auto& movie : movies)
        {
            auto actors = movie->get_actors();
            if (find(actors.begin(), actors.end(), actor) != actors.end())
            {
                result.push_back(*movie);
            }
        }
        return result;
    }

    Movie Storage::get_top_sale_movie(vector<pair<shared_ptr<Movie>, int>> sales)
    {
        if (sales.empty())
        {
            throw ("No sales available.");
        }

        int max_sales = 0;
        shared_ptr<Movie> top_movie = nullptr;

        for (const auto& sale : sales)
        {
            if (sale.second > max_sales)
            {
                max_sales = sale.second;
                top_movie = sale.first;
            }
        }

        return *top_movie;
    }
}