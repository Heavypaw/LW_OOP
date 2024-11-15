#ifndef SQUARE_H
#define SQUARE_H

#include "Figure.h"

template <typename T>
class Square : public Figure<T> {
private:
    T x, y, side;

public:
    Square() : x(0), y(0), side(0) {}
    Square(T x, T y, T side) : x(x), y(y), side(side) {}

    std::pair<T, T> center() const override {
        return {x + side / 2.0, y + side / 2.0};
    }

    void print(std::ostream& os) const override {
        os << "Square: (" << x << ", " << y << "), side = " << side;
    }

    void read(std::istream& is) override {
        is >> x >> y >> side;
    }

    double area() const override {
        return side * side;
    }

    std::shared_ptr<Figure<T>> clone() const override {
        return std::make_shared<Square<T>>(*this);
    }

    std::shared_ptr<Figure<T>> move() override {
        return std::make_shared<Square<T>>(std::move(*this));
    }

    bool operator==(const Figure<T>& other) const override {
        const Square* otherSquare = dynamic_cast<const Square*>(&other);
        if (!otherSquare) return false;
        return x == otherSquare->x && y == otherSquare->y && side == otherSquare->side;
    }
};

#endif // SQUARE_H