#pragma once
#include <sstream>
#include <ostream>
#include <iostream>
#include <tuple>

using namespace std;

namespace queue
{
    template <class T, class U>
    struct Pair;

    template <class T, class U>
    string ToString(const Pair<T, U>& pair);

    template <class T, class U>
    struct Pair
    {
        T first_element;
        U second_element;

        Pair(T f, U s);
        Pair();

        T first() const;
        U second() const;

        tuple<T, U> get_array() const;

        string ToString() const;

        friend ostream& operator<<(ostream& out, const Pair<T, U>& pair)
        {
            return out << "(" << pair.first() << "; " << pair.second() << ")";
        }
    };
}

namespace queue
{
    template <class T, class U>
    string ToString(const Pair<T, U>& pair)
    {
        stringstream buffer{};
        buffer << pair.first() << ", " << pair.second();
        return buffer.str();
    }

    template <class T, class U>
    Pair<T, U>::Pair(T first_element, U second_element) : first_element(first_element), second_element(second_element) {}

    template<class T, class U>
    inline Pair<T, U>::Pair()
    {
    }

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
    tuple<T, U> Pair<T, U>::get_array() const
    {
        return make_tuple(first_element, second_element);
    }

    template <class T, class U>
    string Pair<T, U>::ToString() const
    {
        stringstream buffer{};
        buffer << first_element << ", " << second_element;
        return buffer.str();
    }
}