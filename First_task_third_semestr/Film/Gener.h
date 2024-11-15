#pragma once
#include <iostream>
#include <sstream>
#include <ostream>
#include <vector>
#include <string>
#include "Film.h"

using namespace std;

namespace film
{
	class Genres
	{
	private:
		
		shared_ptr<Movie> movie;
		vector<shared_ptr<string>> genres;
		

	public:
		Genres();
		Genres(vector<shared_ptr<string>> geners, shared_ptr<Movie> movie);
		void add_genre(const string& genre);
		string get_genres() const;
	};
}