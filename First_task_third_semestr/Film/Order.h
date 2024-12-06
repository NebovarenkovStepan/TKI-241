#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include "Film.h"

using namespace std;

namespace film
{
    class Movie;
    class Storage;
    bool operator==(const Order& lha, const Order& rha);
    bool operator==(const shared_ptr<Order>& lha, const shared_ptr<Order>& rha);

    class Order final : public enable_shared_from_this<Order>
    {

    private:

        vector<pair<shared_ptr<Movie>, chrono::system_clock::time_point>> orders;
        vector<pair<shared_ptr<Movie>, int>> sales;
        string title;

    public:

        Order(const string& title);
        static shared_ptr<Order> create_order(const string& title);
        void add_oder(shared_ptr<Movie> movie);
        void add_sale(shared_ptr<Movie> movie);
    };
}

