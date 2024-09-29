#include "film.h"

using namespace std;

namespace film
{
		Movie::Movie(string title, string genre, string director) 
		: title(title), genre(genre), director(director){}

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
