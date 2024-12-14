#include <iostream>
#include <locale>
#include"..//Solver/Generator.h"
#include"..//Solver/Matrix.h"
#include"..//Solver/Random_generator.h"
#include"..//Solver/My_exercise.h"

using namespace matrix;

int main()
{
    std::unique_ptr<Generator> randomGenerator = std::make_unique<RandomGenerator>(1, 100);

    My_exercise exercise(3, 3, std::move(randomGenerator));

    exercise.run();

    return 0;
}