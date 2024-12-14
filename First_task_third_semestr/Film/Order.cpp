#include "Order.h"

namespace Movie
{
    Order::Order(const std::string& title) : title{ title }, price_of_movie{0}
    {
        
    }

    std::shared_ptr<Order> Order::create_order(const std::string& title)
    {
        return make_shared<Order>(Order{ title });
    }

    void Order::add_oder(std::shared_ptr<Movie>& movie)
    {
        std::pair<std::shared_ptr<Movie>, std::chrono::system_clock::time_point> order(movie.get(), std::chrono::system_clock::now());
        movie.get()->order = shared_from_this();
        movie.get()->increase_sales();
    }

    void Order::add_price(std::shared_ptr<Movie>& movie) 
    {
        if (movie) 
        {
            price_of_movie = movie->get_price();
        }
    }

    std::string Order::to_string()
    {
        std::stringstream buffer;
        buffer << "Order Title: " << title << "\n"
            << "Price of Movie: " << price_of_movie << "\n"
            << "Movie: " << (order.first ? order.first->get_title() : "No movie ordered") << "\n"
            << "Order Time: ";
        std::time_t timet = std::chrono::system_clock::to_time_t(order.second);
        std::tm tm;
        localtime_s(&tm, &timet);
        buffer << "Time: " << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << "\n";
        return buffer.str();
    }

    std::wstring ToString(Order& order)
    {
        auto temp = order.to_string();
        return std::wstring{ temp.cbegin(), temp.cend() };
    }
}
