#include"Storage.h"

using namespace std;

namespace film
{
	void Storage::add_movie(const Movie& movie)
	{
		movies.push_back(movie);
	}

	Movie* Storage::search_by_title(const string& title)
    {
        for (auto& movie : movies)
        {
            if (movie.get_title() == title)
            {
                return &movie;
            }
        }
        return nullptr;
    }

    vector<Movie> Storage::search_by_genre(const string& genre)
    {
        vector<Movie> result;
        for (const auto& movie : movies)
        {
            if (movie.get_genre() == genre)
            {
                result.push_back(movie);
            }
        }
        return result;
    }

    vector<Movie> Storage::search_by_director(const string& director)
    {
        vector<Movie> result;
        for (const auto& movie : movies)
        {
            if (movie.get_director() == director)
            {
                result.push_back(movie);
            }
        }
        return result;
    }

    vector<Movie> Storage::search_by_actor(const string& actor)
    {
        vector<Movie> result;
        for (const auto& movie : movies)
        {
            auto actors = movie.get_actors();
            if (find(actors.begin(), actors.end(), actor) != actors.end())
            {
                result.push_back(movie);
            }
        }
        return result;
    }

    vector<string> Storage::get_media_for_movie(const string& title)
    {
        Movie* movie = search_by_title(title);
        if (movie)
        {
            return movie->get_media();
        }
    }

    vector<Movie> Storage::get_top_selling_movies(int top)
    {
        {
            vector<Movie> sortedMovies = movies;
            sort(sortedMovies.begin(), sortedMovies.end(), [](const Movie& a, const Movie& b) 
                {
                return a.get_sales() > b.get_sales();
                });

            if (top > sortedMovies.size()) 
            {
                top = sortedMovies.size();
            }

            return vector<Movie>(sortedMovies.begin(), sortedMovies.begin() + top);
        }
    }

    double Storage::get_total_sales()
    {
        {
            double totalSales = 0;
            for (const auto& movie : movies)
            {
                totalSales += movie.get_sales();
            }
            return totalSales;
        }
    }


}