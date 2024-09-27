#include "people.h"

film::Person::Person(string name, string surname, string patronymic) : name(name), surname(surname), patronymic(patronymic){}

string film::Person::ToString() const
{
    stringstream buffer{};
    buffer << name << " " << surname << " " << patronymic;
    return buffer.str();
}

string film::Person::get_name()
{
    return name;
}

string film::Person::get_surname()
{
    return surname;
}

string film::Person::get_patronymic()
{
    return patronymic;
}
