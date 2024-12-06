#pragma once

#include "matrix.h"
#include "generator.h"

namespace matrix
{
    /**
    * @brief обстрактный базовый класс exercise, представляющий задачу, которая может быть выполнена над матрицей.
    */
    class Exercise
    {
    protected:
        /**
        * @brief ссылка на матрицу, над которой будет выполняться задача.
        */
        Matrix matrix;

        /**
        * @brief ссылка на генератор значений, используемый для заполнения матрицы.
        */
        Generator& generator;

    public:
        /**
        * @brief конструктор класса Exercise.
        * @param matrix ссылка на матрицу, над которой будет выполняться задача.
        * @param generator ссылка на генератор значений.
        */
        Exercise(Matrix& matrix, Generator& generator);

        /**
        * @brief виртуальный деструктор.
        */
        ~Exercise();

        /**
        * @brief чисто виртуальный метод для выполнения задачи Task1.
        */
       void task1();

        /**
        * @brief яисто виртуальный метод для выполнения задачи Task2.
        */
        void task2();
    };
}