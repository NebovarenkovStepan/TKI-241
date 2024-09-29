#include "Gener.h"

namespace film
{
	void Genres::add_genre(const string& genre)
	{
		genres.push_back(genre);
	}

	string Genres::get_genres()
	{
		stringstream buffer{};
		buffer << "Geners: \n";
		size_t i = 0;
		for (; i < genres.size() - 1; i++)
		{
			buffer << genres[i] << ", ";
		}
		buffer << genres[i + 1] << ".\n";
		return buffer.str();
	}
}