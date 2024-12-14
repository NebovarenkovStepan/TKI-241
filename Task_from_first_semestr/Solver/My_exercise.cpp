#include "My_exercise.h"
#include <algorithm>
#include <iostream>

namespace matrix
{
	std::string My_exercise::title() const noexcept
	{
		return "Exercise";
	}

	void My_exercise::task_1()
	{
        int columns = matrix->get_columns();
        int rows = matrix->get_rows();
        for (int j = 0; j < columns; ++j)
        {
            int maxAbs = 0;
            for (int i = 0; i < rows; ++i)
            {
                maxAbs = std::max(maxAbs, std::abs((*matrix)[i][j]));
            }

            for (int i = 0; i < rows; ++i)
            {
                if ((*matrix)[i][j] % 2 == 0)
                {
                    (*matrix)[i][j] = maxAbs;
                }
            }
        }
        out << *matrix << std::endl;
	}

    void My_exercise::task_2()
    {
        int columns = matrix->get_columns();
        int rows = matrix->get_rows();
        std::vector<bool> columns_to_keep(columns, true);
        int counter = columns;

        for (int j = columns - 1; j >= 0; --j)
        {
            if ((*matrix)[0][j] % 2 == 0)
            {
                columns_to_keep[j] = false;
                counter -= 1;
            }
        }

        Matrix new_matrix(rows, counter);
        int new_column_index = 0;

        for (int i = 0; i < rows; ++i)
        {
            new_column_index = 0;
            for (int j = 0; j < columns; ++j)
            {
                if (columns_to_keep[j])
                {
                    new_matrix[i][new_column_index] = (*matrix)[i][j];
                    new_column_index++;
                }
            }
        }

        *matrix = new_matrix;

        out << *matrix << std::endl;
    }
}