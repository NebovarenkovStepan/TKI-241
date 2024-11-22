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

    class Order final : public enable_shared_from_this<Order>
    {

    private:

        vector<pair<shared_ptr<Movie>, string>> orders;
        string order_date;
        vector<pair<shared_ptr<Movie>, int>> sales;
        string title;
        int amount;

    public:

        Order(const string& title);
        static shared_ptr<Order> create_order(const string& title);
        void add_oder(shared_ptr<Movie> movie);
        void add_sale(shared_ptr<Movie> movie);
        string get_current_time();
    };
}

