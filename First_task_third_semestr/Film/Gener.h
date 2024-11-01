#pragma once
#include <iostream>
#include <sstream>
#include <ostream>
#include <vector>
#include <string>
#include "film.h"

using namespace std;

namespace film
{
	class Genres
	{
	private:
		
		shared_ptr<Movie> movie;
		vector<weak_ptr<string>> genres;
		void add_genre(const string& genre);

	public:
		Genres();
		Genres(vector<weak_ptr<string>> geners, shared_ptr<Movie> movie);

		string get_genres() const;
	};
}