#pragma once
#include "Pair.h"
#include <sstream>
#include <ostream>
#include <cstring>

using namespace std;

namespace queue
{
	template <typename T>
	class Vector
	{
	public:
		explicit Vector(const int size);
		Vector();
		Vector(initializer_list<T> values);
		Vector(const Vector<T>& other);
		~Vector();
		void push_back(const T& element);
		Vector<T>& operator=(const Vector& other);
		T& operator[](int index);

	private:
		T* array;
		int size;
		int capacity;
	};
}


