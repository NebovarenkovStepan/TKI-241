#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <optional>
#include <vector>

#include"Film.h"

using namespace std;

class Movie;

namespace film 
{

    class Person : public std::enable_shared_from_this<Person>
    {
    public:
        Person(const string& name, const string& surname, const std::optional<string>& patronymic);

       ~Person();

       void add_film_directors(shared_ptr<Movie>& movie);
       void add_film_actors(shared_ptr<Movie>& movie);

        string ToString() const;
        string get_name() const;
        string get_surname() const;
        string get_patronymic() const;
        shared_ptr<Person> create_person(const string& name, const string& surname, const optional<string>& patronymic);
        vector<shared_ptr<Movie>> movies;

    private:
        string name;
        string surname;
        optional<string> patronymic;
        string full_name;
    };

   
}