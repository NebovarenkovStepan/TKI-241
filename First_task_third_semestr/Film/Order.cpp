#include "Order.h"

namespace film
{
    Order::Order(const string& title) : order_date(get_current_time()), title(title)
    {
        
    }

    shared_ptr<Order> Order::create_order(const string& title)
    {
        return make_shared<Order>(Order{ title });
    }

    void Order::add_oder(shared_ptr<Movie> movie)
    {
        pair<shared_ptr<Movie>, string> order(movie.get(), this->order_date);
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

	string Order::get_current_time()
    {
        auto now = chrono::system_clock::now();
        time_t currentTime = chrono::system_clock::to_time_t(now);

        tm localTime;
        localtime_s(&localTime, &currentTime);

        ostringstream oss;
        oss << put_time(&localTime, "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }
}
