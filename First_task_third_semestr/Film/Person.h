#pragma once
#include <memory>
#include <string>
#include <optional>
#include <vector>


namespace Movie
{
    class Person;
    bool operator==(const Person& lha, const Person& rha);
    bool operator==(const std::shared_ptr<Person>& lha, const std::shared_ptr<Person>& rha);

    class Movie;

    class Person final : public std::enable_shared_from_this<Person>
    {
    public:
       
       void add_film_directors(std::shared_ptr<Movie> const& movie);
       void add_film_actors(std::shared_ptr<Movie> const& movie);

        std::string to_string() const;
        std::string get_name() const;
        std::string get_surname() const;
        std::string get_patronymic() const;
        std::shared_ptr<Person> create_person(const std::string& name, const std::string& surname, const std::optional<std::string>& patronymic);
        std::vector<std::shared_ptr<Movie>> movies{};
        Person(const std::string& name, const std::string& surname, const std::optional<std::string>& patronymic = std::nullopt);

    private:
        std::string name;
        std::string surname;
        std::optional<std::string> patronymic;
        std::string full_name;
        
    };

   
}