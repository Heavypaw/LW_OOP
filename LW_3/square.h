#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square : public Figure {
private:
    double x, y, side;

public:
    Square() : x(0), y(0), side(0) {}
    Square(double x, double y, double side) : x(x), y(y), side(side) {}

    std::pair<double, double> center() const override {
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

    Square* clone() const override {
        return new Square(*this);
    }

    Square* move() override {
        return new Square(std::move(*this));
    }

    bool operator==(const Figure& other) const override {
        const Square* otherSquare = dynamic_cast<const Square*>(&other);
        if (!otherSquare) return false;
        return x == otherSquare->x && y == otherSquare->y && side == otherSquare->side;
    }
};

#endif 
