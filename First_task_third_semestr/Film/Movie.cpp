#include "Movie.h"

#include <sstream>
#include <iostream>

namespace Movie
{
		Movie::Movie(const std::string& title, const double price, std::vector<std::shared_ptr<Genre>> genres, std::vector<std::shared_ptr<Person>> directors, std::vector<std::shared_ptr<Person>> actors) : title(title), price(price), genres(genres), directors(directors), actors(actors), sales(0){}

		std::shared_ptr<Movie> Movie::create_movie(const std::string& title, const double price, std::vector<std::shared_ptr<Genre>> genres, std::vector<std::shared_ptr<Person>> directors, std::vector<std::shared_ptr<Person>> actors)
		{
			return make_shared<Movie>(Movie{title, price, genres, directors,  actors});
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

		Movie::Movie() : title("Empty"){}

		std::vector<std::shared_ptr<Genre>> Movie::get_genres() const
		{
			return this->genres;
		}

		std::vector<std::shared_ptr<Person>> Movie::get_directors() const
		{
			return this->directors;
		}

		std::vector<std::shared_ptr<Person>> Movie::get_actors() const
		{
			return this->actors;
		}
		double Movie::get_price() const
		{
			return this->price;
		}

		void Movie::increase_sales()
		{
			this->sales += 1;
		}

		int Movie::get_sales()
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

		bool operator==(const std::shared_ptr<Movie>& lha, const std::shared_ptr<Movie>& rha)
		{
			return lha.get()->to_string() == rha.get()->to_string();
		}
}
