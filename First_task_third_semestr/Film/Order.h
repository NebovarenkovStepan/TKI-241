#pragma once
#include <string>
#include <chrono>
#include "Movie.h"

namespace Movie
{
    class Order;
    std::wstring ToString(const Order& order);

    class Movie;
    class Storage;

    class Order final : public std::enable_shared_from_this<Order>
    {

    private:

        std::pair<std::shared_ptr<Movie>, std::chrono::system_clock::time_point> order;
        double price_of_movie;
        std::string title;
        explicit Order(const std::string& title);

    public:

        static std::shared_ptr<Order> create_order(const std::string& title);
        void add_oder(std::shared_ptr<Movie>& movie);
        void add_price(std::shared_ptr<Movie>& movie);
        std::string to_string();
    };
}

