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
    class People;
    class Storage;

    class Movie final : public enable_shared_from_this<Movie>
    {
    private:
        string title;
        vector<shared_ptr<string>> genres;
        vector<shared_ptr<Person>> directors;
        vector<shared_ptr<Person>> actors;

    public:
        Movie(const string& title, vector<shared_ptr<string>> genres, vector<shared_ptr<Person>> directors, vector<shared_ptr<Person>> actors);

        static shared_ptr<Movie>create_movie(const string& title, vector<shared_ptr<string>> genres, vector<shared_ptr<Person>> directors, vector<shared_ptr<Person>> actors);
        string get_title() const;
        shared_ptr<Storage> storage;
        string to_string();
        vector<shared_ptr<string>> get_genres() const;
        vector<shared_ptr<Person>> get_directors() const;
        vector<shared_ptr<Person>> get_actors() const;
    };

}