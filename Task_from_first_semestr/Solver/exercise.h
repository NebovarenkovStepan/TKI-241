#pragma once

#include "../Solver/generator.h"
#include "../Solver/matrix.h"

#include <iostream>
#include <memory>

namespace matrix
{
    class exercise
    {
    protected:
        Matrix* matrix;

        std::ostream& out;

        virtual std::string title() const noexcept = 0;

        virtual void task_1() = 0;

        virtual void task_2() = 0;

    public:
        explicit exercise(
            const int rows,
            const int columns,
            std::unique_ptr<Generator> generator,
            std::ostream& out = std::cout);

        virtual ~exercise();

        void run();
    };
}