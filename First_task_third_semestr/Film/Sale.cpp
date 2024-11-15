#include "Sale.h"

using namespace std;

namespace film
{
	Sale::Sale(double sale, shared_ptr<Storage> storage) : sale(sale), storage(move(storage)){}

	void Sale::set_sale(const double new_sale)
	{
		if (sale < 0)
		{
			throw("Sale can not be less then zero!");
		}
		sale = new_sale;
	}

	double Sale::get_sale()
	{
		return sale;
	}
}

