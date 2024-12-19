#pragma once

#include "../Solver/Generator.h"
#include "../Solver/Matrix.h"

#include <iostream>
#include <memory>

namespace matrix
{
    class Exercise_virtual
    {
    protected:

        std::unique_ptr<Matrix> matrix;
        std::ostream& out;

        virtual std::string title() const noexcept = 0;

        virtual void task_1() = 0;

        virtual void task_2() = 0;

    public:
        explicit Exercise_virtual(
            const int rows,
            const int columns,
            std::unique_ptr<Generator> generator,
            std::ostream& out = std::cout);

        virtual ~Exercise_virtual();

        void run();
    };
}