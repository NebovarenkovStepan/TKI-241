#include "Movie.h"

#include <sstream>
#include <iostream>

namespace Movie
{
	Movie::Movie(const std::string title, const double price) : title(title), price(price) {}

	std::shared_ptr<Movie> Movie::create_movie(const std::string& title, const double price)
	{
		return std::make_shared<Movie>(Movie{ title, price });
	}

	std::string Movie::get_title() const
	{
		return title;
	}

	std::string Movie::to_string() const
	{
		std::stringstream buffer;

		buffer << "Title: ";
		buffer << this->title << "\n";

		buffer << "Directors: ";
		for (size_t i = 0; i < directors.size(); ++i)
		{
			buffer << directors[i]->to_string();
			if (i < directors.size() - 1)
			{
				buffer << ", ";
			}
		}
		buffer << ".\n";

		buffer << "Genres: ";
		for (size_t i = 0; i < genres.size(); ++i)
		{
			buffer << genres[i]->to_string();
			if (i < genres.size() - 1)
			{
				buffer << ", ";
			}
		}
		buffer << ".\n";

		buffer << "Actors: ";
		for (size_t i = 0; i < actors.size(); ++i)
		{
			buffer << actors[i]->to_string();
			if (i < actors.size() - 1)
			{
				buffer << ", ";
			}
		}
		buffer << ".\n";

		return buffer.str();
	}

	void Movie::add_genres(std::vector<std::shared_ptr<Genre>>& genres)
	{
		for (const auto& genre : genres)
		{
			genres.push_back(genre);
			genre.get()->movie = shared_from_this();
		}
	}

	void Movie::add_actors(std::vector<std::shared_ptr<Actor>>& actors)
	{
		for (const auto& actor : actors)
		{
			actors.push_back(actor);
			actor.get()->movie = shared_from_this();
		}
	}

	void Movie::add_directors(std::vector<std::shared_ptr<Actor>>& directors)
	{
		for (const auto& director : directors)
		{
			actors.push_back(director);
			director.get()->movie = shared_from_this();
		}
	}

	Movie::Movie() : title("Empty"), sales(0), price(0) {}

	std::vector<std::shared_ptr<Genre>> Movie::get_genres() const
	{
		return this->genres;
	}

	std::vector<std::shared_ptr<Director>> Movie::get_directors() const
	{
		return this->directors;
	}

	std::vector<std::shared_ptr<Actor>> Movie::get_actors() const
	{
		return this->actors;
	}
	double Movie::get_price() const
	{
		return this->price;
	}

	void Movie::increase_sales(int amount)
	{
		this->sales += amount;
	}

	int Movie::get_sales() const
	{
		return this->sales;
	}

	std::wstring ToString(const Movie& movie)
	{
		auto temp = movie.to_string();
		return { temp.cbegin(), temp.cend() };
	}

	bool operator==(const Movie& lha, const Movie& rha)
	{
		return lha.to_string() == rha.to_string();
	}
}