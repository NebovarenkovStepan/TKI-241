#include "Random_generator.h"

using namespace std;

namespace matrix
{
	RandomGenerator::RandomGenerator(const int min, const int max)
	{
		this->generator = mt19937(random_device{}());
		this->distribution = uniform_int_distribution<int>(min, max);
	}

	int RandomGenerator::generate()
	{
		return this->distribution(this->generator);
	}
}
