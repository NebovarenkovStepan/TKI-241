#include "i_genrator.h"
#include <exception>

using namespace std;

namespace matrix
{
	IStreamGenerator::IStreamGenerator(istream& in) : in{ in } {}

	int IStreamGenerator::generate()
	{
		int value;
		if (!(this->in >> value))
		{
			throw logic_error("Wrong value");
		}

		return value;
	}
}