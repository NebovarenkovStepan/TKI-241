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

    class Person
    {
        friend class Actor;
        friend class Director;

    public:

        std::string to_string() const;
        std::string get_name() const;
        std::string get_surname() const;
        std::string get_patronymic() const;

    private:
        std::string name;
        std::string surname;
        std::optional<std::string> patronymic;
        std::string full_name;
        Person(const std::string& name, const std::string& surname, const std::optional<std::string>& patronymic = std::nullopt);

    };


}