#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Movie.h"

using namespace std;

namespace Movie
{
    class Film;
    class Storage;
    class Order;

    bool operator==(const Storage& lha, const Storage& rha);
    bool operator==(const std::shared_ptr<Storage>& lha, const std::shared_ptr<Storage>& rha);

    class Person;
    class Genre;

    class Storage final : public enable_shared_from_this<Storage>
    {

    private:

        vector<Movie*> movies;
        std::string name;

    public:

        Storage(const std::string& name);

        static std::shared_ptr<Storage> create_storage(const std::string& name);

        void add_movie(std::shared_ptr<Movie> movie);

        void remove_movie(std::shared_ptr<Movie> movie);

        std::string search_by_title(const std::string& title); 

        vector<Movie> search_by_genre(const std::string& genre); 

        vector<Movie> search_by_director(const std::string& director);

        vector<Movie> search_by_actor(const std::string& actor);

        Movie get_top_sale_movie(vector<pair<std::shared_ptr<Movie>, int>> sales);
    };
}