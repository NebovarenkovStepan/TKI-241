#include "Storage.h"

using namespace std;

namespace film
{
    /*
    void Storage::add_movie(const shared_ptr<Movie>& movie)
    {
        movies.push_back(movie); 
    }

    shared_ptr<Movie> Storage::search_by_title(const string& title)
    {
        for (const auto& movie : movies)
        {
            if (movie->get_title() == title)
            {
                return movie; 
            }
        }
        return nullptr;
    }

    vector<shared_ptr<Movie>> Storage::search_by_genre(const string& genre)
    {
        vector<shared_ptr<Movie>> result;
        for (const auto& movie : movies)
        {
            if (movie->get_genre() == genre)
            {
                result.push_back(movie);
            }
        }
        return result; 
    }

    vector<shared_ptr<Movie>> Storage::search_by_director(const string& director)
    {
        vector<shared_ptr<Movie>> result;
        for (const auto& movie : movies)
        {
            if (movie->get_director() == director)
            {
                result.push_back(movie); 
            }
        }
        return result;
    }

    vector<shared_ptr<Movie>> Storage::search_by_actor(const string& actor)
    {
        vector<shared_ptr<Movie>> result;
        for (const auto& movie : movies)
        {
            auto actors = movie->get_actors(); 
            if (find(actors.begin(), actors.end(), actor) != actors.end())
            {
                result.push_back(movie); 
            }
        }
        return result; 
    }

    vector<shared_ptr<Movie>> Storage::get_top_selling_movies(int top)
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
    */
}