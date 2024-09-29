#pragma once
#include <iostream>
#include <sstream>
#include <ostream>
#include <string>

using namespace std;

namespace film 
{
	struct Sale
	{
		double sale;

		Sale(const double& sale);
		void set_sale(const double& new_sale);
		double get_sale();
	};
}
