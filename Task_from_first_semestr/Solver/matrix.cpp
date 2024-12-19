#include "Matrix.h"
#include "Generator.h"

namespace matrix
{
    Matrix::Matrix(int rows, int columns) : rows(rows), columns(columns), data(rows, vector<int>(columns)) {}

    Matrix::Matrix(const Matrix& other) : rows(other.rows), columns(other.columns), data(other.data) {}

    Matrix::Matrix(Matrix&& other) noexcept : rows(other.rows), columns(other.columns), data(move(other.data))
    {
        other.rows = 0;
        other.columns = 0;
    }

    Matrix& Matrix::operator=(const Matrix& other)
    {
        if (this != &other)
        {
            rows = other.rows;
            columns = other.columns;
            data = other.data;
        }
        return *this;
    }

    Matrix& Matrix::operator=(Matrix&& other) noexcept
    {
        if (this != &other)
        {
            rows = other.rows;
            columns = other.columns;
            data = move(other.data);
            other.rows = 0;
            other.columns = 0;
        }
        return *this;
    }

    vector<int>& Matrix::operator[](int index)
    {
        return data[index];
    }

    const vector<int>& Matrix::operator[](int index) const
    {
        return data[index];
    }

    int Matrix::get_rows() const
    {
        return rows;
    }

    int Matrix::get_columns() const
    {
        return columns;
    }

    void Matrix::fill(Generator& generator)
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                data[i][j] = generator.generate();
            }
        }
    }

    void Matrix::print(ostream& os) const
    {
        for (const auto& row : data)
        {
            for (const auto& elem : row)
            {
                os << elem << " ";
            }
            os << endl;
        }
    }

    Matrix::Matrix(int rows, int columns, Generator& generator) : rows(rows), columns(columns), data(rows, std::vector<int>(columns))
    {
        fill(generator);
    }

    std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
    {
        for (int i = 0; i < matrix.rows; ++i)
        {
            for (int j = 0; j < matrix.columns; ++j)
            {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }
}
