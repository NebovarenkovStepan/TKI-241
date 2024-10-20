#pragma once
#include <sstream>
#include <ostream>
#include <cstring>
#include <initializer_list>

using namespace std;

namespace hash
{

	template <typename T>
	class HashTable
	{
	public:
		string ToString() const;
		HashTable(int size);
		~HashTable();
		
	private:
		int hashing(const string& srt, const int size, const int key);
		int start(const string& str, const int size);
		int step(const string& str, const int size);
		void resize();
		struct element
		{
			T value;
			bool state; 
			element(const T& value) : value(value), state(true) {}
		};
		element**  array;
		size_t size;
		size_t amount_of_elements;
		size_t counter;
	};
}

namespace hash
{
	template<typename T>
	HashTable<T>::HashTable(int size) : size(size)
	{
		amount_of_elements = 0;
		if (size <= 0)
		{
			throw logic_error("Размер должен быть больше 0!");
		}

		this->size = static_cast<size_t>(size);
		this->array = new element*[this->size];
		for (size_t i = 0; i < size; i++)
		{
			this->array[i] = nullptr;
		}
	}

	template<typename T>
	inline string HashTable<T>::ToString() const
	{
		stringstream buffer{};
		buffer << "[";
		size_t i = 0;
		for (; i < size - 1; i++)
		{
			buffer << this->array[i] << ", ";
		}
		buffer << this->array[i] << "]";

		return buffer.str();
	}

	template <class T>
	HashTable<T>::~HashTable()
	{
		for (size_t i = 0; i < this->size; ++i)
			if (array[i])
				delete array[i];
		delete[] array;
	}

	template<typename T>
	inline int HashTable<T>::hashing(const string& srt, const int size, const int key)
	{
		int hash_result = 0;
		for (int i = 0; str[i] != str.size(); ++i)
			hash_result = (key * hash_result + s[i]) % size;
		hash_result = (hash_result * 2 + 1) % size;
		return hash_result;
	}

	template<typename T>
	inline int HashTable<T>::start(const string& str, const int size)
	{
		return hasing(str, size, size - 1);
	}

	template<typename T>
	inline int HashTable<T>::step(const string& str, const int size)
	{
		return hashing(str, size, size + 1);
	}

	template<typename T>
	inline void HashTable<T>::resize()
	{
		int prev_size = this->size;
		this->size *= 2;
		amount_of_elements = 0;
		counter = 0;
		element** new_array = new element*[this->size];
		swap(this->array, new_array);
		for (size_t i = 0; i < prev_size; ++i)
		{
			if (new_array[i] && new_array[i]->state)
				add_element(new_array[i]->value);
		}
		
	}


}
