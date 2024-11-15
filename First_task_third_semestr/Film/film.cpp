#include "Film.h"

using namespace std;

namespace film
{
		Movie::Movie(const string& title, vector<shared_ptr<string>> genres, vector<shared_ptr<Person>> directors, vector<shared_ptr<Person>> actors) : title(title), genres(genres), directors(directors), actors(actors){}

		shared_ptr<Movie> Movie::create_movie(const string& title, vector<shared_ptr<string>> genres, vector<shared_ptr<Person>> directors, vector<shared_ptr<Person>> actors)
		{
			return make_shared<Movie>(Movie{ title, genres, directors,  actors});
		}

		string Movie::get_title() const
		{
			return title;
		}

		string Movie::to_string()
		{
			stringstream buffer;

			buffer << "Title: ";
			buffer << this->title << "\n";

			buffer << "Directors: ";
			for (size_t i = 0; i < directors.size(); ++i)
			{
				buffer << directors[i]->ToString();
				if (i < directors.size() - 1)
				{
					buffer << ", ";
				}
			}
			buffer << ".\n";

			buffer << "Genres: ";
			for (size_t i = 0; i < genres.size(); ++i)
			{
				buffer << *genres[i];
				if (i < genres.size() - 1)
				{
					buffer << ", ";
				}
			}
			buffer << ".\n";

			buffer << "Actors: ";
			for (size_t i = 0; i < actors.size(); ++i)
			{
				buffer << actors[i]->ToString();
				if (i < actors.size() - 1)
				{
					buffer << ", ";
				}
			}
			buffer << ".\n";
		}

		vector<shared_ptr<string>> Movie::get_genres() const
		{
			return this->genres;
		}

		vector<shared_ptr<Person>> Movie::get_directors() const
		{
			return this->directors;
		}

		vector<shared_ptr<Person>> Movie::get_actors() const
		{
			return this->actors;
		}
}
