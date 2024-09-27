#pragma once

#include <sstream>
#include <ostream>
#include <iostream>
#include "people.h"

using namespace std;

namespace film
{
	struct Person
	{
		string name;
		string surname;
		string patronymic;
		Person(string name, string surname, string patronymic);

		string ToString() const;
		string get_name();
		string get_surname();
		string get_patronymic();
	};
}