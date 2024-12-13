#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Movie.h"
#include "Order.h"
#include "Person.h"
#include "Genre.h"

namespace Movie
{
    class Film;
    class Storage;
    class Order;

    class Person;
    class Genre;

    class Storage final : public std::enable_shared_from_this<Storage>
    {

    private:

        std::vector<Movie*> movies;
        std::shared_ptr<Movie> movie;
        std::string name;

    public:

        Storage(const std::string& name);

        static std::shared_ptr<Storage>create_storage(const std::string& name);

        void add_movie(std::shared_ptr<Movie> movie);

        void remove_movie(std::shared_ptr<Movie> movie);

        std::string search_by_title(const std::string& title); 

        std::vector<Movie> search_by_genre(const std::string& genre); 

        std::vector<Movie> search_by_director(const std::string& director);

        std::vector<Movie> search_by_actor(const std::string& actor);

        Movie get_top_sale_movie();
    };
}