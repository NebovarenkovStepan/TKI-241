#include "people.h"
#include <sstream>
#include <string>
#include <optional>

#include"Film.h"

namespace film 
{
    Person::Person(const std::string& name, const std::string& surname, const std::optional<std::string>& patronymic) : name{ name }, surname{ surname }, patronymic{ patronymic }
    {
        std::stringstream buffer{};
        if (this->patronymic.has_value()) 
        {
            buffer << this->name << " " << this->surname << " " << this->patronymic.value();
        }
        else {
            buffer << this->name << " " << this->surname;
        }
        this->full_name = buffer.str();
    }

    void Person::add_film_directors(std::shared_ptr<Movie> const& movie)
    {
        this->movies.push_back(movie);
        movie->get_directors().push_back(shared_from_this());
    }

    void Person::add_film_actors(std::shared_ptr<Movie> const& movie)
    {
        this->movies.push_back(movie);
        movie->get_actors().push_back(shared_from_this());
    }

    string Person::to_string() const
    {
        std::stringstream buffer{};
        buffer << this->full_name;
        return buffer.str();
    }

    std::string Person::get_name() const 
    {
        return this->name;
    }

    std::string Person::get_surname() const 
    {
        return this->surname;
    }

    std::string Person::get_patronymic() const 
    {
        return this->patronymic.has_value() ? this->patronymic.value() : "Empty";
    }

    std::shared_ptr<Person> Person::create_person(const std::string& name, const std::string& surname, const std::optional<std::string>& patronymic) 
    {
        return make_shared<Person>(name, surname, patronymic);
    }
    bool operator==(const Person& lha, const Person& rha)
    {
        return lha.to_string() == rha.to_string();
    }

    bool operator==(const std::shared_ptr<Person>& lha, const std::shared_ptr<Person>& rha)
    {
        return lha.get()->to_string() == rha.get()->to_string();
    }
}