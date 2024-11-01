#include "Film.h"

using namespace std;

namespace film
{
		Movie::Movie(string title, vector<weak_ptr<string>> genres, vector<weak_ptr<string>> directors) : title(title), genres(genres), directors(directors){}

		string Movie::get_title() const
		{
			return title;
		}

		vector<weak_ptr<string>> Movie::get_genre() const
		{
			return genres;
		}

		vector<weak_ptr<string>> Movie::get_director() const
		{
			return directors;
		}

		vector<weak_ptr<string>> Movie::get_actors() const
		{
			return actors;
		}
}
