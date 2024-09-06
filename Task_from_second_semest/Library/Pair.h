#pragma once
#include <sstream>
#include <ostream>
#include <iostream>

using namespace std;

namespace queue
{
	template <class T, class U>
	struct Pair;
	template <class T, class U>
	wstring ToString(const Pair<T, U>& pair);

	template <class T, class U>
	struct Pair
	{
		T first_element;
		U second_element;
		Pair(T f, U s);

		T first() const;

		U second() const;

		auto get_array();

		string ToString() const;
	};
}


