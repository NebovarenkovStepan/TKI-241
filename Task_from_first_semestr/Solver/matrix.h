#pragma once
#include "generator.h"
#include <vector>
#include <iostream>

using namespace std;

namespace matrix
{
    /**
    * @brief Класс Matrix представляет двумерный массив (матрицу) целых чисел.
    */
    class Matrix
    {
    private:
        /**
        * @brief Двумерный массив целых чисел, представляющий матрицу.
        */
        vector<vector<int>> data;

        /**
        * @brief Количество строк в матрице.
        */
        int rows;

        /**
        * @brief Количество столбцов в матрице.
        */
        int columns;

    public:
        /**
        * @brief Конструктор для создания матрицы с заданным количеством строк и столбцов.
        * @param rows Количество строк в матрице.
        * @param columns Количество столбцов в матрице.
        */
        Matrix(int rows, int columns);

        /**
        * @brief Конструктор копирования.
        * @param other Матрица, которую нужно скопировать.
        */
        Matrix(const Matrix& other);

        /**
        * @brief Конструктор перемещения.
        * @param other Матрица, данные которой нужно переместить.
        */
        Matrix(Matrix&& other) noexcept;

        /**
        * @brief Оператор присваивания копированием.
        * @param other Матрица, данные которой нужно скопировать.
        * @return Ссылка на текущую матрицу.
        */
        Matrix& operator=(const Matrix& other);

        /**
        * @brief Оператор присваивания перемещением.
        * @param other Матрица, данные которой нужно переместить.
        * @return Ссылка на текущую матрицу.
        */
        Matrix& operator=(Matrix&& other) noexcept;

        /**
        * @brief Оператор доступа к элементу матрицы по индексу строки.
        * @param index Индекс строки.
        * @return Ссылка на вектор, представляющий строку матрицы.
        */
        vector<int>& operator[](int index);

        /**
        * @brief Оператор доступа к элементу матрицы по индексу строки (константный).
        * @param index Индекс строки.
        * @return Константная ссылка на вектор, представляющий строку матрицы.
        */
        const vector<int>& operator[](int index) const;

        /**
        * @brief Возвращает количество строк в матрице.
        * @return Количество строк в матрице.
        */
        int get_rows() const;

        /**
        * @brief Возвращает количество столбцов в матрице.
        * @return Количество столбцов в матрице.
        */
        int get_columns() const;

        /**
        * @brief Заполняет матрицу значениями, сгенерированными объектом Generator.
        * @param generator Объект, генерирующий значения для заполнения матрицы.
        */
        void fill(Generator& generator);

        /**
        * @brief Выводит содержимое матрицы в поток вывода.
        * @param os Поток вывода, в который будет выведено содержимое матрицы.
        */
        void print(ostream& os) const;
    };
}