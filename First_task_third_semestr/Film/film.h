#pragma once
#include <iostream>
#include <sstream>
#include <ostream>
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

    public:
        Movie(string title, string genre, string director);

        string get_title() const;
        string get_genre() const;
        string get_director() const;

        string display_info() const;
    };

}


