#pragma once
#include <iostream>
#include <sstream>
#include <ostream>
#include <string>
#include "Storage.h"

using namespace std;

namespace film
{
	class Sale
	{
	private:
		shared_ptr<Storage> storage;
		double sale;

	public:
		Sale(double sale, shared_ptr<Storage> storage);
		void set_sale(const double new_sale);
		double get_sale();
	};
}
