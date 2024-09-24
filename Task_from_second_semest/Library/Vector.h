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
        friend ostream& operator<<(ostream& out, const Vector<T>& vector);
    private:
        T* array;
        int size;
        int capacity;
    };
}

namespace queue
{
    template <class T>
    T& Vector<T>::operator[](int index)
    {
        return array[index];
    }

    template<class T>
    Vector<T>::Vector(const int size) : size(size), capacity(size)
    {
        array = new T[size];
    }

    template<typename T>
    Vector<T>::Vector() : array(nullptr), size(0), capacity(1)
    {
        array = new T[capacity];
    }

    template<class T>
    Vector<T>::Vector(initializer_list<T> values) : size(values.size()), capacity(values.size()), array(new T[this->capacity])
    {
        int i = 0;
        for (const T& value : values)
        {
            if (i < size)
            {
                array[i] = value;
                i++;
            }
        }
    }

    template<class T>
    Vector<T>::Vector(const Vector<T>& other) : size(other.size), capacity(other.capacity), array(new T[this->capacity])
    {
        for (int i = 0; i < size; i++)
        {
            array[i] = other.array[i];
        }
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

    template <class T>
    ostream& operator<<(ostream& out, const Vector<T>& vector)
    {
        out << "[";
        for (int i = 0; i < vector.size; i++)
        {
            out << vector.array[i];
            if (i != vector.size - 1)
            {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }
}