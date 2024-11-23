#include "people.h"
#include <sstream>

namespace film {

    Person::Person(const string& name, const string& surname, const std::optional<string>& patronymic)
        : name(name), surname(surname), patronymic(patronymic) {
        stringstream buffer{};
        if (this->patronymic.has_value()) {
            buffer << this->name << " " << this->surname << " " << this->patronymic.value();
        }
        else {
            buffer << this->name << " " << this->surname;
        }
        this->full_name = buffer.str();
    }

    Person::~Person() {}

    void Person::add_film_directors(shared_ptr<Movie>& movie)
    {
        this->movies.push_back(movie);
        movie->get_directors().push_back(shared_from_this());
    }

    void Person::add_film_actors(shared_ptr<Movie>& movie)
    {
        this->movies.push_back(movie);
        movie->get_actors().push_back(shared_from_this());
    }

    string Person::to_string() const
    {
        stringstream buffer{};
        buffer << this->full_name;
        return buffer.str();
    }

    string Person::get_name() const 
    {
        return this->name;
    }

    string Person::get_surname() const 
    {
        return this->surname;
    }

    string Person::get_patronymic() const 
    {
        return this->patronymic.has_value() ? this->patronymic.value() : "Empty";
    }

    shared_ptr<Person> Person::create_person(const string& name, const string& surname, const optional<string>& patronymic) 
    {
        return make_shared<Person>(name, surname, patronymic);
    }
}