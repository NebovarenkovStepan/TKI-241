#include "Storage.h"

using namespace std;

namespace film
{
    Storage::Storage(const string& name) : name(name)
    {}

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
        auto it = find_if(movies.begin(), movies.end(), [=](const Movie* movie) {return movie->get_title() == title;});

        if (it != movies.end())
        {
            return (*it)->to_string();
        }
        return "There are no movies with this title.";
    }

    vector<Movie> Storage::search_by_genre(const string& genre)
    {
        vector<Movie> result;
        transform(movies.begin(), movies.end(), back_inserter(result), [=](const Movie* movie)
        {
            auto genres = movie->get_genres();
            if (find(genres.begin(), genres.end(), genre) != genres.end())
            {
                return *movie;
            }
        });
        return result;
    }

    vector<Movie> Storage::search_by_director(const string& director)
    {
        vector<Movie> result;
        transform(movies.begin(), movies.end(), back_inserter(result), [=](const Movie* movie)
            {
                auto directors = movie->get_directors();
                if (find(directors.begin(), directors.end(), director) != directors.end())
                {
                    return *movie;
                }
            });
        return result;
    }

    vector<Movie> Storage::search_by_actor(const string& actor)
    {
        vector<Movie> result;
        transform(movies.begin(), movies.end(), back_inserter(result), [=](const Movie* movie)
        {
            auto actors = movie->get_actors();
            if (find(actors.begin(), actors.end(), actor) != actors.end())
            {
                return *movie;
            }
        });
        return result;
    }

    Movie Storage::get_top_sale_movie(vector<pair<shared_ptr<Movie>, int>> sales)
    {
        if (sales.empty())
        {
            throw out_of_range("No sales available.");
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