#pragma once
#include <sstream>
#include <ostream>
#include <iostream>
#include "Film.h"

using namespace std;

namespace film
{
	class Person
	{
	private:
		shared_ptr<Movie> movie;
		string name;
		string surname;
		string patronymic;
		Person(string& name, string& surname, string& patronymic, shared_ptr<Movie> movie);
		Person(string& name, string& surname, shared_ptr<Movie> movie);

		string ToString() const;
		string get_name();
		string get_surname();
		string get_patronymic();
	};
}