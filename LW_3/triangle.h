#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle : public Figure {
private:
    double x1, y1, x2, y2, x3, y3;

public:
    Triangle() : x1(0), y1(0), x2(0), y2(0), x3(0), y3(0) {}
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}

    std::pair<double, double> center() const override {
        double cx = (x1 + x2 + x3) / 3.0;
        double cy = (y1 + y2 + y3) / 3.0;
        return {cx, cy};
    }

    void print(std::ostream& os) const override {
        os << "Triangle: (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << "), (" << x3 << ", " << y3 << ")";
    }

    void read(std::istream& is) override {
        is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    }

    double area() const override {
        return 0.5 * std::abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
    }

    Triangle* clone() const override {
        return new Triangle(*this);
    }

    Triangle* move() override {
        return new Triangle(std::move(*this));
    }

    bool operator==(const Figure& other) const override {
        const Triangle* otherTriangle = dynamic_cast<const Triangle*>(&other);
        if (!otherTriangle) return false;
        return x1 == otherTriangle->x1 && y1 == otherTriangle->y1 &&
               x2 == otherTriangle->x2 && y2 == otherTriangle->y2 &&
               x3 == otherTriangle->x3 && y3 == otherTriangle->y3;
    }
};

#endif 
