#include <iostream>
#include <algorithm>

#include "Storage.h"
#include "Genre.h"

namespace Movie
{
    Storage::Storage(const std::string& name) : name(name)
    {}

    std::shared_ptr<Storage> Storage::create_storage(const std::string& name)
    {
        return make_shared<Storage>(Storage{ name });
    }


    void Storage::add_movie(std::shared_ptr<Movie> movie)
    {
        this->movies.push_back(movie.get());
        movie.get()-> storage = shared_from_this();
    }

    void Storage::remove_movie(std::shared_ptr<Movie> movie)
    {
        this->movies.erase(std::remove(this->movies.begin(), this->movies.end(), movie.get()), this->movies.end());
        movie.get()-> storage = nullptr;
    }

    std::string Storage::search_by_title(const std::string& title)
    {
        auto it = find_if(movies.begin(), movies.end(), [=](const Movie* movie) {return movie->get_title() == title;});

        if (it != movies.end())
        {
            return (*it)->to_string();
        }
        return "There are no movies with this title.";
    }

    std::vector<Movie> Storage::search_by_genre(const std::string& genre)
    {
        std::vector<Movie> result;
        transform(movies.begin(), movies.end(), back_inserter(result), [=](const Movie* movie)
        {
            auto genres = movie->get_genres();
            std::vector<string> string_genres;
            for (const auto& genres_to_string : genres)
            {
                string_genres.push_back(genres_to_string.get()->to_string());
            }
            if (find(string_genres.begin(), string_genres.end(), genre) != string_genres.end())
            {
                return *movie;
            }
        });
        return result;
    }

    std::vector<Movie> Storage::search_by_director(const std::string& director)
    {
        std::vector<Movie> result;
        transform(movies.begin(), movies.end(), back_inserter(result), [=](const Movie* movie)
            {
                auto directors = movie->get_directors();
                std::vector<string> string_directors;
                for (const auto& director_to_string : directors)
                {
                    string_directors.push_back(director_to_string.get()->to_string());
                }
                if (find(string_directors.begin(), string_directors.end(), director) != string_directors.end())
                {
                    return *movie;
                }
            });
        return result;
    }

    std::vector<Movie> Storage::search_by_actor(const std::string& actor)
    {
        std::vector<Movie> result;
        transform(movies.begin(), movies.end(), back_inserter(result), [=](const Movie* movie)
        {
            auto actors = movie->get_actors();
            std::vector<string> string_actors;
            for (const auto& actor_to_string : actors)
            {
                string_actors.push_back(actor_to_string.get()->to_string());
            }
            if (find(string_actors.begin(), string_actors.end(), actor) != string_actors.end())
            {
                return *movie;
            }
        });

        return result;
    }

    Movie Storage::get_top_sale_movie(std::vector<pair<std::shared_ptr<Movie>, int>> sales)
    {
        if (sales.empty())
        {
            throw out_of_range("No sales available.");
        }

        int max_sales = 0;
        std::shared_ptr<Movie> top_movie = nullptr;

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

    bool operator==(const Storage& lha, const Storage& rha)
    {
        return false;
    }

    bool operator==(const std::shared_ptr<Storage>& lha, const std::shared_ptr<Storage>& rha)
    {
        return false;
    }
}