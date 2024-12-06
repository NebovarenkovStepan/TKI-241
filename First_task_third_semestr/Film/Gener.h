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
	class Movie;
	class Genre;
	bool operator==(const Genre& lha, const Genre& rha);
	bool operator==(const shared_ptr<Genre>& lha, const shared_ptr<Genre>& rha);

	class Genre final : public std::enable_shared_from_this<Genre>
	{
	private:
		
		vector<Movie*> movies;
		shared_ptr<Movie> movie;
		string genre;
		

	public:
		Genre(string genre);
		static shared_ptr<Genre> create_genre(string genre);
		Genre(const string& genre, shared_ptr<Movie> movie);
		void add_movie(shared_ptr<Movie> movie);
		string get_genre() const;
	};
}