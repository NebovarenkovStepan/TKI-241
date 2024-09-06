#include "Pair.h"

namespace queue
{
	template <class T, class U>
	wstring ToString(const Pair<T, U>& pair)
	{
		wstringstream buffer{};
		buffer << pair.first() << L", " << pair.second();

		return buffer.str();
	}

	template <class T, class U>
	Pair<T, U>::Pair(T f, U s) : first_element(f), second_element(s) {}

	template <class T, class U>
	T Pair<T, U>::first() const
	{
		return first_element;
	}

	template <class T, class U>
	U Pair<T, U>::second() const
	{
		return second_element;
	}

	template<class T, class U>
	auto Pair<T, U>::get_array()
	{
		auto array = { first_element, second_element };
		return array;
	}



	template <class T, class U>
	string Pair<T, U>::ToString() const
	{
		stringstream buffer{};
		buffer << this->first_element << ", " << this->second_element;
		return buffer.str();
	}
}