#pragma once
#include "Exercise_virtual.h"
#include "Matrix.h"

namespace matrix
{
    class My_exercise : public Exercise_virtual
    {
    public:
        My_exercise(
            const int rows,
            const int columns,
            std::unique_ptr<Generator> generator,
            std::ostream& out = std::cout)
            : Exercise_virtual(rows, columns, std::move(generator), out) {}

    protected:
        std::string title() const noexcept override;
        void task_1() override;
        void task_2() override;
    };
}