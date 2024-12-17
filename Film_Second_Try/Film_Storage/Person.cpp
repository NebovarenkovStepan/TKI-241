#include "Person.h"
#include <sstream>
#include <string>
#include <optional>

namespace Movie
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

    std::string Person::to_string() const
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

    bool operator==(const Person& lha, const Person& rha)
    {
        return lha.to_string() == rha.to_string();
    }

    bool operator==(const std::shared_ptr<Person>& lha, const std::shared_ptr<Person>& rha)
    {
        return lha.get()->to_string() == rha.get()->to_string();
    }
}
