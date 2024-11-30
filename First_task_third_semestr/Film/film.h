#pragma once
#include <iostream>
#include <sstream>
#include <ostream>
#include <string>
#include <memory>
#include <algorithm>
#include <unordered_map>
#include "people.h"
#include "Gener.h"
#include "Storage.h"

using namespace std;

namespace film 
{
    class Order;
    class Genre;
    class Person;
    class Storage;


    wstring to_string(const Movie& movie);
    bool operator==(const Movie& lha, const Movie& rha);
    class Movie final : public enable_shared_from_this<Movie>
    {
    private:
        string title;
        double price;
        vector<shared_ptr<Genre>> genres;
        vector<shared_ptr<Person>> directors;
        vector<shared_ptr<Person>> actors;

    public:
        Movie(const string& title, const double& price, vector<shared_ptr<Genre>> genres, vector<shared_ptr<Person>> directors, vector<shared_ptr<Person>> actors);

        static shared_ptr<Movie>create_movie(const string& title, const double& price, vector<shared_ptr<Genre>> genres, vector<shared_ptr<Person>> directors, vector<shared_ptr<Person>> actors);
        string get_title() const;
        shared_ptr<Storage> storage;
        shared_ptr<Order> order;
        string to_string() const;
        vector<shared_ptr<Genre>> get_genres() const;
        vector<shared_ptr<Person>> get_directors() const;
        vector<shared_ptr<Person>> get_actors() const;
        double get_price() const;
    };

}