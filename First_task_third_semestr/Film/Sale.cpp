#include "Sale.h"

namespace film
{
	Sale::Sale(const double& sale) : sale(sale){}

	void Sale::set_sale(const double& new_sale)
	{
		sale = new_sale;
	}

	double Sale::get_sale()
	{
		return sale;
	}
}

