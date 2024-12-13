#include "Order.h"

namespace Movie
{
    Order::Order(const string& title) : title{ title }, price_of_movie{0}
    {
        
    }

    shared_ptr<Order> Order::create_order(const string& title)
    {
        return make_shared<Order>(Order{ title });
    }

    void Order::add_oder(shared_ptr<Movie>& movie)
    {
        pair<shared_ptr<Movie>, chrono::system_clock::time_point> order(movie.get(), chrono::system_clock::now());
        movie.get()->order = shared_from_this();
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
        return wstring{ temp.cbegin(), temp.cend() };
    }

    bool operator==(const Order& lha, const Order& rha)
    {
        return false;
    }

    bool operator==(const shared_ptr<Order>& lha, const shared_ptr<Order>& rha)
    {
        return false;
    }
}
