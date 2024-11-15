#include "Order.h"

namespace film
{
	Order::Order(double price) : order_date(get_current_time()), price(price){}

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
