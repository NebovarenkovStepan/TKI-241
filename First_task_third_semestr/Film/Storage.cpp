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
        movie.get()->storage = shared_from_this();
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

    /*vector<shared_ptr<Movie>> Storage::get_top_selling_movies(int top)
    {
        vector<shared_ptr<Movie>> sortedMovies = movies;
        sort(sortedMovies.begin(), sortedMovies.end(), [](const shared_ptr<Movie>& a, const shared_ptr<Movie>& b)
            {
                return a->get_total_sales() > b->get_total_sales();
            });

        if (top > sortedMovies.size())
        {
            top = sortedMovies.size();
        }

        return vector<shared_ptr<Movie>>(sortedMovies.begin(), sortedMovies.begin() + top);
    }

    double Storage::get_total_sales()
    {
        double totalSales = 0;
        for (const auto& movie : movies)
        {
            totalSales += movie->get_total_sales();

            return totalSales;
        }
    }*/
}