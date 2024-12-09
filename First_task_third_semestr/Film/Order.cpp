#include "Order.h"

namespace film
{
    Order::Order(const string& title) : title{ title }
    {
        
    }

    shared_ptr<Order> Order::create_order(const string& title)
    {
        return make_shared<Order>(Order{ title });
    }

    void Order::add_oder(shared_ptr<Movie>& movie)
    {
        pair<shared_ptr<Movie>, chrono::system_clock::time_point> order(movie.get(), chrono::system_clock::now());
        this->orders.push_back(order);
        add_sale(movie);
        movie.get()->order = shared_from_this();
    }

    void Order::add_sale(shared_ptr<Movie> movie)
    {
        auto it = find_if(sales.begin(), sales.end(), [&movie](const auto& sale) { return sale.first == movie; });

        if (it != sales.end())
        {
            it->second += 1;
        }
        else
        {
            sales.emplace_back(movie, 1);
        }
    }

    std::string Order::to_string()
    {
        stringstream buffer;
        for (const auto &order : orders)
        {
            buffer << "Order: " << order.first->to_string() << " ";
            std::time_t timeT = std::chrono::system_clock::to_time_t(order.second);
            std::tm tm = *localtime(&timeT);
            buffer << "Time: " << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
        }
    }

    std::wstring to_string(const Order& order)
    {
        //return
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
