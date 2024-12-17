#include "Director.h"

#include "Movie.h"

namespace Movie
{
	Director::Director(const std::string& name, const std::string& surname, const std::optional<std::string>& patronymic)
		: Person(name, surname, patronymic), name(name), surname(surname), patronymic(patronymic) {}

	std::shared_ptr<Director> Director::create_director(const std::string& name, const std::string& surname, const std::optional<std::string>& patronymic)
	{
		return std::make_shared<Director>(Director{ name, surname, patronymic });
	}

	void Director::add_film_directors(std::shared_ptr<Movie> const& movie)
	{
		this->movies.push_back(movie);
		movie->get_directors().push_back(shared_from_this());
	}
}