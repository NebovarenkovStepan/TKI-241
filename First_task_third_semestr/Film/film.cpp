#include "film.h"

using namespace std;

namespace film
{
		Movie::Movie(string title, string genre, string director, vector<string> actors, vector<string> media, double sales) 
		: title(title), genre(genre), director(director), actors(actors), media(media), sales(sales) {}

		string Movie::get_title() const
		{
			return title;
		}

		string Movie::get_genre() const
		{
			return genre;
		}

		string Movie::get_director() const
		{
			return director;
		}

		vector<string> Movie::get_actors() const
		{
			return actors;
		}

		vector<string> Movie::get_media() const
		{
			return media;
		}

		double Movie::get_sales() const
		{
			return sales;
		}

		string Movie::display_info() const
		{
			stringstream buffer{};

			buffer << "Title: " << title << "\n";
			buffer << "Genre: " << genre << "\n";
			buffer << "Director: " << director << "\n";
			buffer << "Actors: ";
			for (const auto& actor : actors) 
			{
				buffer << actor << " ";
			}
			buffer << "\n";
			buffer << "Available on: ";
			for (const auto& i : media) 
			{
				buffer << i << " ";
			}
			buffer << "\n";
			buffer << "Sales: $" << sales << "\n";
			return buffer.str();
		}
}
