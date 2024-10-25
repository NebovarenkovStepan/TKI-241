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

    template<typename T>
    wostream& operator<< (std::wostream& os, const Vector<T>& vector);

    template <typename T>
    class Vector final
    {
    public:
        explicit Vector(const int size);
        Vector();
        Vector(initializer_list<T> values);
        Vector(const Vector<T>& other);
        Vector<T>(Vector<T>&& other);
        ~Vector();
        void push_back(const T& element);
        Vector<T>& operator=(const Vector& other);
        Vector& operator=(Vector&& other) noexcept;
        T& operator[](size_t index);
        T operator[](size_t index) const;
       
        string to_string() const;
        size_t get_size() const;

    private:
        size_t size;
        size_t capacity;
        T* array;

        bool is_full() const noexcept;

        void expand();
        void swap(Vector<T>& other) noexcept;
    };

}

namespace queue
{
    template <class T>
    T& Vector<T>::operator[](size_t index)
    {
        if (index > this->size)
        {
            throw logic_error("Индекс должен быть меньше размера вектора!");
        }
        return array[index];
    }

    template<typename T>
    Vector<T>::Vector(Vector<T>&& other) : array(other.array)
    {
        *this = move(other);
    }

    template<typename T>
    inline string Vector<T>::to_string() const
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
    Vector<T>::Vector(const int size) : Vector()
    {
        if (size <= 0)
        {
            throw std::logic_error("Размер массива должен быть неотрицательным!");
        }

        this->size = static_cast<size_t>(size);
        this->capacity = this->size * 2;
        this->array = new T[this->capacity];
    }

    template<typename T>
    Vector<T>::Vector() : size(0), capacity(0), array(nullptr)
    {
    }

    template<class T>
    Vector<T>::Vector(initializer_list<T> values) : size(values.size()), capacity(values.size()), array(new T[this->capacity])
    {
        std::copy(values.begin(), values.end(), this->array);
    }

    template<class T>
    Vector<T>::Vector(const Vector<T>& other) : size(other.size), capacity(other.capacity), array(new T[this->capacity])
    {
        std::copy(other.array, other.array + other.size, this->array);
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
            this->swap(temp);
        }
        return *this;
    }

    template<typename T>
    inline Vector<T>& Vector<T>::operator=(Vector&& other) noexcept
    {
        if (this != &other)
        {
            this->swap(other);
        }

        return *this;
    }

    template<typename T>
    inline T Vector<T>::operator[](size_t index) const
    {
        return this->array[index];
    }

    template<typename T>
    inline void Vector<T>::swap(Vector<T>& other) noexcept
    {
        std::swap(other.capacity, this->capacity);
        std::swap(other.array, this->array);
        std::swap(other.size, this->size);
    }

    template <class T>
    void Vector<T>::push_back(const T& element)
    {
        if (this->is_full())
        {
            this->expand();
        }

        this->array[this->size++] = element;
    }


    template<typename T>
    wstring ToString(const Vector<T>& vector)
    {
        auto temp = vector.to_string();
        return wstring{ temp.cbegin(), temp.cend() };
    }

    template <class T>
    ostream& operator<<(ostream& out, const Vector<T>& vector)
    {
        return out << vector.to_string();
    }

    template<typename T>
    wostream& operator<<(wostream& out, const Vector<T>& vector)
    {
        /*auto temp = vector.ToString();
        wstring ws{ temp.cbegin(), temp.cend() };*/

        return out << ToString(vector);
    }

    template<typename T>
    inline bool Vector<T>::is_full() const noexcept
    {
        return this->capacity <= this->size;
    }

    template<typename T>
    inline void Vector<T>::expand()
    {
        Vector temp(this->size);
        //for (size_t i = 0; i < this->size; ++i)
        //{
        //    temp.data[i] = this->data[i];
        //}
        std::copy(this->array, this->array + this->size, temp.array);

        this->swap(temp);
    }
}