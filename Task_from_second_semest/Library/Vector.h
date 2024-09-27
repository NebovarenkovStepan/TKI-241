#pragma once
#include <sstream>
#include <ostream>
#include <cstring>
#include <initializer_list>
#include "Pair.h"

using namespace std;

namespace queue
{
    template <typename T>
    class Vector;

    template <typename T>
    wstring ToString(const Vector<T>& vector);

    template <typename T>
    ostream& operator<<(ostream& out, const Vector<T>& vector);

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
        T& operator[](size_t index);
        T operator[](size_t index) const;
       
        string ToString() const;
        size_t get_size() const;

    private:
        T* array;
        size_t size;
        size_t capacity;
    };

}

namespace queue
{
    template <class T>
    T& Vector<T>::operator[](size_t index)
    {
        return array[index];
    }

    template<typename T>
    inline string Vector<T>::ToString() const
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

    template<typename T>
    inline size_t Vector<T>::get_size() const
    {
        return this->size;
    }

    template<class T>
    Vector<T>::Vector(const int size) : size(size), capacity(size)
    {
        if (size <= 0)
        {
            throw std::logic_error("–азмер массива должен быть неотрицательным!");
        }
        this->size = static_cast<size_t>(size);
        this->capacity(size);
        array = new T[size];
    }

    template<typename T>
    Vector<T>::Vector() : array(nullptr), size(0), capacity(0)
    {
    }

    template<class T>
    Vector<T>::Vector(initializer_list<T> values) : size(values.size()), capacity(values.size()), array(new T[this->capacity])
    {
        copy(values.begin(), values.end(), this->array);
    }

    template<class T>
    Vector<T>::Vector(const Vector<T>& other) : size(other.size), capacity(other.size), array(new T[this->capacity])
    {
        copy(this->array, this->array + this->size, other.array);
    }

    template <class T>
    Vector<T>::~Vector()
    {
        delete[] array;
    }

    template<class T>
    Vector<T>& Vector<T>::operator=(const Vector& other)
    {
        if (this != &other)
        {
            Vector temp(other);
            swap(temp.array, this->array);
            swap(temp.size, this->size);
            swap(temp.capacity, this->capacity);
        }
        return *this;
    }

    template<typename T>
    inline T Vector<T>::operator[](size_t index) const
    {
        return this->array[index];
    }

    template <class T>
    void Vector<T>::push_back(const T& element)
    {
        if (size == capacity)
        {
            capacity *= 2;
            T* new_array = new T[capacity];
            for (int i = 0; i < size; i++)
            {
                new_array[i] = array[i];
            }
            delete[] array;
            array = new_array;
        }
        size++;
        array[size] = element;
    }


    template<typename T>
    wstring ToString(const Vector<T>& vector)
    {
        wstringstream out{};
        out << L"[";
        size = this->size;
        for (size_t i = 0; i < size; i++)
        {
            out << vector[i];
            if (i < size)
            {
                out << L", ";
            }
        }
        out << L"]";

        return out.str();
    }

    template <class T>
    ostream& operator<<(ostream& out, const Vector<T>& vector)
    {
        stringstream buffer{};
        size_t i = 0;
        for (; i < vector.get_size() - 1; ++i)
        {
            buffer << vector[i] << ", ";
        }
        buffer << vector[i];

        return out << buffer.str();
    }
}