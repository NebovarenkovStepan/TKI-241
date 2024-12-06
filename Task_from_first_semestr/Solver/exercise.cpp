#include "exercise.h"

using namespace std;

namespace matrix
{
	Exercise::Exercise(Matrix& matrix, Generator& generator) : matrix(matrix), generator(generator) {}

	Exercise::~Exercise(){}

	void Exercise::task1()
	{
		int max_element = this->matrix[0][0];

	}

	void Exercise::task2()
	{
	}
}