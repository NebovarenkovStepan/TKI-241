#include "Exercise_virtual.h"


namespace matrix
{
	Exercise_virtual::Exercise_virtual(const int rows, const int columns, std::unique_ptr<Generator> generator, std::ostream& out) : out(out)
	{
		matrix = std::make_unique<Matrix>(rows, columns, *generator);
	}
	Exercise_virtual::~Exercise_virtual() = default;

	void Exercise_virtual::run()
	{
		out << title() << std::endl;

		out << "Matrix:" << std::endl;
		out << *matrix << std::endl;

		out << "First task:" << std::endl;
		task_1();

		out << "Second task:" << std::endl;
		task_2();
	}


}