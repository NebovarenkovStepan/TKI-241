
#include <iostream>
#include <algorithm>
#include "Storage.h"
#include "Movie.h"
#include "Genre.h"

namespace Movie
{
    Storage::Storage(const std::string& name) : name(name)
    {}

    std::shared_ptr<Storage> Storage::create_storage(const std::string& name)
    {
        return std::make_shared<Storage>(Storage{ name });
    }

    void Storage::add_movie(std::shared_ptr<Movie>& movie)
    {
        this->movies.push_back(movie.get());
        movie->storage = shared_from_this();
    }

    void Storage::remove_movie(std::shared_ptr<Movie> movie)
    {
        this->movies.erase(std::remove(this->movies.begin(), this->movies.end(), movie.get()), this->movies.end());
        movie->storage = nullptr;
    }

    std::string Storage::search_by_title(const std::string& title)
    {
        auto it = std::find_if(movies.begin(), movies.end(), [=](const Movie* movie) { return movie->get_title() == title; });

        if (it != movies.end())
        {
            return (*it)->to_string();
        }
        return "There are no movies with this title.";
    }

    std::vector<Movie> Storage::search_by_genre(const std::string& genre)
    {
        std::vector<Movie> result;
        std::transform(movies.begin(), movies.end(), std::back_inserter(result), [=](const Movie* movie)
            {
                auto genres = movie->get_genres();
                std::vector<std::string> string_genres;
                for (const auto& genre_ptr : genres)
                {
                    string_genres.push_back(genre_ptr->to_string());
                }
                if (std::find(string_genres.begin(), string_genres.end(), genre) != string_genres.end())
                {
                    return *movie;
                }
                return Movie();
            });
        return result;
    }

    std::vector<Movie> Storage::search_by_director(const std::string& director)
    {
        std::vector<Movie> result;
        std::transform(movies.begin(), movies.end(), std::back_inserter(result), [=](const Movie* movie)
            {
                auto directors = movie->get_directors();
                std::vector<std::string> string_directors;
                for (const auto& director_ptr : directors)
                {
                    string_directors.push_back(director_ptr->to_string());
                }
                if (std::find(string_directors.begin(), string_directors.end(), director) != string_directors.end())
                {
                    return *movie;
                }
                return Movie();
            });
        return result;
    }

    std::vector<Movie> Storage::search_by_actor(const std::string& actor)
    {
        std::vector<Movie> result;
        std::transform(movies.begin(), movies.end(), std::back_inserter(result), [=](const Movie* movie)
            {
                auto actors = movie->get_actors();
                std::vector<std::string> string_actors;
                for (const auto& actor_ptr : actors)
                {
                    string_actors.push_back(actor_ptr->to_string());
                }
                if (std::find(string_actors.begin(), string_actors.end(), actor) != string_actors.end())
                {
                    return *movie;
                }
                return Movie();
            });

        return result;
    }

    Movie Storage::get_top_sale_movie()
    {
        int max_sales = 0;
        Movie* top_movie = nullptr;

        for (const auto& movie : movies)
        {
            int sale = movie->get_sales();
            if (sale >= max_sales)
            {
                max_sales = sale;
                top_movie = movie;
            }
        }

        return *top_movie;
    }
}
