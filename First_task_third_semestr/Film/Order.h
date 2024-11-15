#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include "Film.h"

using namespace std;

namespace film
{
    class Order 
    {

    private:

        vector<shared_ptr<Movie>> order_movies;
        string order_date;
        double price;

    public:

        Order(double price);

        string get_current_time();
    };
}

