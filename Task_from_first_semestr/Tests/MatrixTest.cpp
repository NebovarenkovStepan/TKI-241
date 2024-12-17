#include <iostream>
#include "pch.h"
#include "CppUnitTest.h"
#include "..//Solver/Matrix.h"
#include "..//Solver/Generator.h"
#include"..//Solver/Random_generator.h"
#include"..//Solver/My_exercise.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace matrix;

namespace Tests
{

    class MockGenerator : public matrix::Generator 
    {
    public:
        int value;
        MockGenerator(int startValue) : value(startValue) {}
        int generate() override 
        {
            return value++;
        }
    };

    TEST_CLASS(MatrixTest)
    {
    public:

        TEST_METHOD(Matrix_Constructor_Success)
        {
            // Arrange
            int rows = 2;
            int columns = 3;

            // Act
            Matrix matrix(rows, columns);
            int expected_rows = matrix.get_rows();
            int expected_columns = matrix.get_columns();

            // Assert
            Assert::AreEqual(rows, expected_rows);
            Assert::AreEqual(columns, expected_columns);
        }

        TEST_METHOD(Matrix_CopyConstructor_Success)
        {
            // Arrange
            matrix::Matrix original(2, 2);
            MockGenerator generator(1);
            original.fill(generator);

            // Act
            matrix::Matrix copy(original);

            // Assert
            Assert::AreEqual(original.get_rows(), copy.get_rows());
            Assert::AreEqual(original.get_columns(), copy.get_columns());
            Assert::AreEqual(original[0][0], copy[0][0]);
        }

        TEST_METHOD(Matrix_MoveConstructor_Success)
        {
            // Arrange
            matrix::Matrix original(2, 2);
            MockGenerator generator(1);
            original.fill(generator);

            // Act
            matrix::Matrix moved(std::move(original));

            // Assert
            Assert::AreEqual(2, moved.get_rows());
            Assert::AreEqual(2, moved.get_columns());
            Assert::AreEqual(1, moved[0][0]);
        }

        TEST_METHOD(Matrix_IndexOperator_Success)
        {
            // Arrange
            matrix::Matrix matrix(2, 2);
            MockGenerator generator(1);
            matrix.fill(generator);

            // Act
            int actual = matrix[0][0];
            int expected = 1;

            // Assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(Matrix_Fill_Success)
        {
            // Arrange
            matrix::Matrix matrix(2, 2);
            MockGenerator generator(5);

            // Act
            matrix.fill(generator);

            // Assert
            Assert::AreEqual(5, matrix[0][0]);
            Assert::AreEqual(6, matrix[0][1]);
            Assert::AreEqual(7, matrix[1][0]);
            Assert::AreEqual(8, matrix[1][1]);
        }

        TEST_METHOD(Matrix_Print_Success)
        {
            // Arrange
            matrix::Matrix matrix(2, 2);
            MockGenerator generator(1);
            matrix.fill(generator);

            // Act
            std::ostringstream os;
            os << matrix;

            // Assert
            std::string expected_output = "1 2 \n3 4 \n"; 
            Assert::AreEqual(expected_output, os.str());
        }
    };
}
