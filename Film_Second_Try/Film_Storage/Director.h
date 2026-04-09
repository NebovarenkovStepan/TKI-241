#pragma once
#include "Person.h"
#include <vector>
#include "Movie.h"

namespace Movie
{

    class Movie;

    class Director final : public Person, std::enable_shared_from_this<Director>
    {

    private:
        std::string name;
        std::string surname;
        std::optional<std::string> patronymic;
        Director(const std::string& name, const std::string& surname, const std::optional<std::string>& patronymic = std::nullopt);
        std::vector<std::shared_ptr<Movie>> movies{};

    public:
        static std::shared_ptr<Director> create_director(const std::string& name, const std::string& surname, const std::optional<std::string>& patronymic);
        void add_film_directors(std::shared_ptr<Movie> const& movie);
        std::shared_ptr<Movie> movie;

    };
}