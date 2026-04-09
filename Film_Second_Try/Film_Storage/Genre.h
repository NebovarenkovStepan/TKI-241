#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <sstream>
#include "Movie.h"

namespace Movie
{
	class Genre;

	bool operator==(const Genre& lha, const Genre& rha);

	class Movie;

	class Genre final : public std::enable_shared_from_this<Genre>
	{
	private:

		std::vector<Movie*> movies;
		std::string genre;

		Genre(const std::string& genre, std::shared_ptr<Movie> movie);

	public:

		static std::shared_ptr<Genre> create_genre(std::string genre);
		explicit Genre(const std::string& genre);
		void add_genre(std::shared_ptr<Movie>& movie);
		std::string to_string() const;
		std::shared_ptr<Movie> movie;
	};
}