#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include "film.h"


using namespace std;

namespace film
{
    class Storage 
    {
    private:
        vector<Movie> movies;

    public:
        void add_movie(const Movie& movie);

        Movie* search_by_title(const string& title);

        vector<Movie> search_by_genre(const string& genre);

        vector<Movie> search_by_director(const string& director);

        vector<Movie> search_by_actor(const string& actor);

        vector<string> get_media_for_movie(const string& title);

        vector<Movie> get_top_selling_movies(int top);

        double get_total_sales();
    };
}