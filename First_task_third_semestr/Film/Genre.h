#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "Movie.h"

namespace Movie
{
	class Genre;
	bool operator==(const Genre& lha, const Genre& rha);
	bool operator==(const std::shared_ptr<Genre>& lha, const std::shared_ptr<Genre>& rha);

	class Movie;


	class Genre final : public std::enable_shared_from_this<Genre>
	{
	private:
		
		vector<Movie*> movies;
		shared_ptr<Movie> movie;
		std::string genre;
		explicit Genre(const std::string& genre);

	public:
		
		static std::shared_ptr<Genre> create_genre(string genre);
		Genre(const string& genre, std::shared_ptr<Movie> movie);
		void add_movie(std::shared_ptr<Movie>& movie);
		std::string to_string() const;
	};
}