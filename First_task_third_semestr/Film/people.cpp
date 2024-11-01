#include "people.h"

namespace film
{


    Person::Person(string& name, string& surname, string& patronymic, shared_ptr<Movie> movie) : name(name), surname(surname), patronymic(patronymic), movie(move(movie)) {}
    Person::Person(string& name, string& surname, shared_ptr<Movie> movie) : name(name), surname(surname), patronymic(""), movie(move(movie)) {}

    string Person::ToString() const
    {
        stringstream buffer{};
        buffer << name << " " << surname << " " << patronymic;
        return buffer.str();
    }

    string Person::get_name()
    {
        return name;
    }

    string Person::get_surname()
    {
        return surname;
    }

    string Person::get_patronymic()
    {
        return patronymic;
    }

}