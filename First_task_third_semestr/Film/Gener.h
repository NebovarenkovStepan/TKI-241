#pragma once
#include <iostream>
#include <sstream>
#include <ostream>
#include <vector>
#include <string>

using namespace std;

namespace film
{
	struct Genres
	{
		vector<string> genres;

		void add_genre(const string& genre);
		string get_genres();
	};
}