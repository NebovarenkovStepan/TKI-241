#pragma once
#include <iostream>
#include <sstream>
#include <ostream>
#include <string>
#include <memory>
#include <algorithm>
#include <unordered_map>

#include "Gener.h"

using namespace std;

namespace film 
{

    class Movie 
    {
    private:
        string title;
        vector<weak_ptr<string>> genres;
        vector<weak_ptr<string>> directors;
        vector<weak_ptr<string>> actors;

    public:
        Movie(string title, vector<weak_ptr<string>> genres, vector<weak_ptr<string>> directors);

        string get_title() const;
        vector<weak_ptr<string>> get_genre() const;
        vector<weak_ptr<string>> get_director() const;
        vector<weak_ptr<string>> get_actors() const;
    };

}