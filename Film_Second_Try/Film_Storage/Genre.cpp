#include "Genre.h"

#include "Movie.h"

namespace Movie
{
	Genre::Genre(const std::string& genre, std::shared_ptr<Movie> movie) : genre(genre) {}

	Genre::Genre(const std::string& genre) : genre(genre) {}

	void Genre::add_genre(std::shared_ptr<Movie>& movie)
	{
		this->movies.push_back(movie);
		movie->get_genres().push_back(shared_from_this());
	}

	std::string Genre::to_string() const
	{
		std::stringstream buffer;
		buffer << genre;
		return buffer.str();
	}

	std::shared_ptr<Genre> Genre::create_genre(std::string genre)
	{
		return std::make_shared<Genre>(Genre{ genre });
	}

	bool operator==(const Genre& lha, const Genre& rha)
	{
		return lha.to_string() == rha.to_string();
	}

}
