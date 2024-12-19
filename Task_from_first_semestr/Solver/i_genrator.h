#pragma once
#include "Generator.h"
#include <iostream>

using namespace std;

namespace matrix
{
    /**
    * @brief Класс IStreamGenerator, реализующий интерфейс Generator для генерации значений из входного потока.
    */
    class IStreamGenerator : public Generator
    {
    private:
        /**
        * @brief Ссылка на входной поток, из которого будут считываться значения.
        */
        istream& in;

    public:
        /**
        * @brief Конструктор класса IStreamGenerator.
        * @param in Ссылка на входной поток.
        */
        IStreamGenerator(istream& in = cin);

        /**
        * @brief Метод для генерации значения из входного потока.
        * @return Считанное значение типа int.
        */
        int generate() override;
    };
}