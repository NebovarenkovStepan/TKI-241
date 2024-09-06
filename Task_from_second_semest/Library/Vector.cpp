#include "Vector.h"

using namespace std;

namespace queue
{
	template <typename T>
	T& Vector<T>::operator[](int index)
	{
		return array[index];
	}

	template<typename T>
	Vector<T>::Vector(const int size) : size(size), capacity(size)
	{
		array = new T[size];
	}

	template<typename T>
	Vector<T>::Vector() : array(nullptr), size(0), capacity(1)
	{
		array = new T[capacity];
	}

	template<typename T>
	Vector<T>::Vector(initializer_list<T> values) : size(values.size()), capacity(values.size())
	{
		int i = 0;
		array = new initializer_list<T>[size] {values};
		for (const T& value : values)
		{
			if (i < size)
			{
				array[i] = value;
				i++;
			}
		}
	}

	template<typename T>
	Vector<T>::Vector(const Vector<T>& other) : size(other.size()), capacity(other.size())
	{
		array = new Vector<T>[size];
		for (int i = 0; i < size; i++)
		{
			array[i] = other[i];
		}
	}

	template <typename T>
	Vector<T>::~Vector()
	{
		delete[] array;
	}

	template<typename T>
	Vector<T>& Vector<T>::operator=(const Vector& other)
	{
		if (this != &other)
		{
			Vector temp(other);
			swap(temp.array, this->array);
			swap(temp.size, this->size);
		}
		return *this;
	}

	template <typename T>
	void Vector<T>::push_back(const T& element)
	{
		if (size == capacity)
		{
			capacity += 1;
			T* new_array = new T[capacity];
			for (int i = 0; i < size; i++)
			{
				new_array[i] = array[i];
			}
			delete[] array;
			array = new_array;
		}
		array[size] = element;
		size++;
	}
}
