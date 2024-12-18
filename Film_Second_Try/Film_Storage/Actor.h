#pragma once
#include "Person.h"
#include <vector>
#include "Movie.h"

namespace Movie
{
    class Movie;

    class Actor final : public Person, std::enable_shared_from_this<Actor>
    {

    private:

        Actor(const std::string& name, const std::string& surname, const std::optional<std::string>& patronymic = std::nullopt);
        std::string name;
        std::string surname;
        std::optional<std::string> patronymic;
        std::vector<std::shared_ptr<Movie>> movies{};

    public:
        static std::shared_ptr<Actor> create_actor(const std::string& name, const std::string& surname, const std::optional<std::string>& patronymic);

        void add_film_actors(std::shared_ptr<Movie> const& movie);

        std::shared_ptr<Movie> movie;

    };
}