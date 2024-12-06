#pragma once
#include "generator.h"
#include <random>

using namespace std;

namespace matrix
{
    /**
    * @brief Класс RandomGenerator, реализующий интерфейс Generator для генерации случайных целых чисел.
    */
    class RandomGenerator : public Generator
    {
    private:
        /**
        * @brief Объект распределения для генерации случайных чисел в заданном диапазоне.
        */
        uniform_int_distribution<int> distribution;

        /**
        * @brief Объект генератора случайных чисел.
        */
        mt19937 generator;

    public:
        /**
        * @brief Конструктор класса RandomGenerator.
        * @param min Минимальное значение диапазона генерации.
        * @param max Максимальное значение диапазона генерации.
        */
        RandomGenerator(const int min, const int max);

        /**
        * @brief Метод для генерации случайного целого числа.
        * @return Сгенерированное случайное целое число.
        */
        int generate() override;
    };
}
