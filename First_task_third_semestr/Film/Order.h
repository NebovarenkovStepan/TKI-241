#pragma once
#include <string>
#include <chrono>
#include "Film.h"

namespace film
{
    class Order;
    std::wstring to_string(const Order& order);
    bool operator==(const Order& lha, const Order& rha);
    bool operator==(const std::shared_ptr<Order>& lha, const std::shared_ptr<Order>& rha);

    class Movie;
    class Storage;

    class Order final : public std::enable_shared_from_this<Order>
    {

    private:

        std::pair<std::shared_ptr<Movie>, std::chrono::system_clock::time_point> order;
        std::vector<std::pair<std::shared_ptr<Movie>, int>> sales{};
        std::string title;
        explicit Order(const std::string& title);

    public:

        static std::shared_ptr<Order> create_order(const std::string& title);
        void add_oder(std::shared_ptr<Movie>& movie);
        void add_sale(std::shared_ptr<Movie> movie);
        std::string to_string();
    };
}

