#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <memory>
#include <vector>
#include <cmath>

template <typename T>
class Figure {
public:
    virtual ~Figure() = default;

    // Вычисление геометрического центра фигуры вращения
    virtual std::pair<T, T> center() const = 0;

    // Вывод координат вершин фигуры
    virtual void print(std::ostream& os) const = 0;

    // Чтение данных фигуры из потока
    virtual void read(std::istream& is) = 0;

    // Вычисление площади фигуры
    virtual double area() const = 0;

    // Перегрузка оператора << для вывода
    friend std::ostream& operator<<(std::ostream& os, const Figure& fig) {
        fig.print(os);
        return os;
    }

    // Перегрузка оператора >> для чтения
    friend std::istream& operator>>(std::istream& is, Figure& fig) {
        fig.read(is);
        return is;
    }

    // Перегрузка оператора приведения к double для вычисления площади
    operator double() const {
        return area();
    }

    // Виртуальные функции для копирования и перемещения
    virtual std::shared_ptr<Figure> clone() const = 0;
    virtual std::shared_ptr<Figure> move() = 0;

    // Виртуальные функции для сравнения
    virtual bool operator==(const Figure& other) const = 0;
};

#endif // FIGURE_H