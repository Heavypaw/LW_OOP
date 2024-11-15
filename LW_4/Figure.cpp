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

    virtual std::pair<T, T> center() const = 0;

    virtual void print(std::ostream& os) const = 0;

    virtual void read(std::istream& is) = 0;
    virtual double area() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Figure& fig) {
        fig.print(os);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Figure& fig) {
        fig.read(is);
        return is;
    }

    operator double() const {
        return area();
    }

    virtual std::shared_ptr<Figure> clone() const = 0;
    virtual std::shared_ptr<Figure> move() = 0;

    virtual bool operator==(const Figure& other) const = 0;
};

#endif // FIGURE_H