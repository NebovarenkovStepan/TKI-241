#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <variant>
#include "Film.h"

using namespace std;

namespace film
{
    class Film;
    class Storage;
    class Order;

    bool operator==(const Storage& lha, const Storage& rha);
    bool operator==(const shared_ptr<Storage>& lha, const shared_ptr<Storage>& rha);

    class Storage final : public enable_shared_from_this<Storage>
    {

    private:

        vector<Movie*> movies;
        string name;

    public:

        Storage(const string& name);

        static shared_ptr<Storage> create_storage(const string& name);

        void add_movie(shared_ptr<Movie> movie);

        void remove_movie(shared_ptr<Movie> movie);

        string search_by_title(const string& title); 

        vector<Movie> search_by_genre(const string& genre); 

        vector<Movie> search_by_director(const string& director);

        vector<Movie> search_by_actor(const string& actor);

        Movie get_top_sale_movie(vector<pair<shared_ptr<Movie>, int>> sales);
    };
}