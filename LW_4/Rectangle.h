#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"

template <typename T>
class Rectangle : public Figure<T> {
private:
    T x, y, width, height;

public:
    Rectangle() : x(0), y(0), width(0), height(0) {}
    Rectangle(T x, T y, T width, T height) : x(x), y(y), width(width), height(height) {}

    std::pair<T, T> center() const override {
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

    std::shared_ptr<Figure<T>> clone() const override {
        return std::make_shared<Rectangle<T>>(*this);
    }

    std::shared_ptr<Figure<T>> move() override {
        return std::make_shared<Rectangle<T>>(std::move(*this));
    }

    bool operator==(const Figure<T>& other) const override {
        const Rectangle* otherRectangle = dynamic_cast<const Rectangle*>(&other);
        if (!otherRectangle) return false;
        return x == otherRectangle->x && y == otherRectangle->y &&
               width == otherRectangle->width && height == otherRectangle->height;
    }
};

#endif // RECTANGLE_H