#pragma once

namespace matrix
{
    /**
    * @brief јбстрактный класс Generator.
    */
    class Generator
    {
    public:
        /**
        * @brief ƒеструктор.
        */
        virtual ~Generator() = 0 {};

        /**
        * @brief ¬иртуальный метод дл¤ генерации значени¤.
        * @return —генерированное значение(int).
        */
        virtual int generate() = 0;
    };
}