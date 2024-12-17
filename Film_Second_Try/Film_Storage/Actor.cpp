#include "Actor.h"



namespace Movie
{
	Actor::Actor(const std::string& name, const std::string& surname, const std::optional<std::string>& patronymic)
		: Person(name, surname, patronymic), name(name), surname(surname), patronymic(patronymic) {}

	std::shared_ptr<Actor> Actor::create_actor(const std::string& name, const std::string& surname, const std::optional<std::string>& patronymic)
	{
		return std::make_shared<Actor>(Actor{ name, surname, patronymic });
	}
	void Actor::add_film_actors(std::shared_ptr<Movie> const& movie)
	{
		this->movies.push_back(movie);
		movie->get_actors().push_back(shared_from_this());
	}
}