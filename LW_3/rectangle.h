#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle : public Figure {
private:
    double x, y, width, height;

public:
    Rectangle() : x(0), y(0), width(0), height(0) {}
    Rectangle(double x, double y, double width, double height) : x(x), y(y), width(width), height(height) {}

    std::pair<double, double> center() const override {
        return {x + width / 2.0, y + height / 2.0};
    }

    void print(std::ostream& os) const override {
        os << "Rectangle: (" << x << ", " << y << "), width = " << width << ", height = " << height;
    }

    void read(std::istream& is) override {
        is >> x >> y >> width >> height;
    }

    double area() const override {
        return width * height;
    }

    Rectangle* clone() const override {
        return new Rectangle(*this);
    }

    Rectangle* move() override {
        return new Rectangle(std::move(*this));
    }

    bool operator==(const Figure& other) const override {
        const Rectangle* otherRectangle = dynamic_cast<const Rectangle*>(&other);
        if (!otherRectangle) return false;
        return x == otherRectangle->x && y == otherRectangle->y &&
               width == otherRectangle->width && height == otherRectangle->height;
    }
};

#endif
