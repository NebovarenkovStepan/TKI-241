#include "Sale.h"

using namespace std;

namespace film
{
	Sale::Sale(double& sale, shared_ptr<Storage> storage) : sale(sale), storage(move(storage)){}

	void Sale::set_sale(const double& new_sale)
	{
		sale = new_sale;
	}

	double Sale::get_sale()
	{
		return sale;
	}
}

