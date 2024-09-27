#pragma once
#include <iostream>
#include <sstream>
#include <ostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

namespace film 
{

    class Movie 
    {
    private:
        string title;
        string genre;
        string director;
        vector<string> actors;
        vector<string> media;
        double sales;

    public:
        Movie(string title, string genre, string director, vector<string> actors, vector<string> media, double sales);

        string get_title() const;
        string get_genre() const;
        string get_director() const;
        vector<string> get_actors() const;
        vector<string> get_media() const;
        double get_sales() const;

        string display_info() const;
    };

}


