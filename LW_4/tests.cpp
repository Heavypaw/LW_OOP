#include <gtest/gtest.h>
#include "Figure.h"
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Array.h"

// Тест для вычисления площади треугольника
TEST(TriangleTest, AreaCalculation) {
    Triangle<int> t(0, 0, 3, 0, 0, 4);
    EXPECT_NEAR(t.area(), 6.0, 1e-6);
}

// Тест для вычисления площади квадрата
TEST(SquareTest, AreaCalculation) {
    Square<int> s(0, 0, 5);
    EXPECT_NEAR(s.area(), 25.0, 1e-6);
}

// Тест для вычисления площади прямоугольника
TEST(RectangleTest, AreaCalculation) {
    Rectangle<int> r(0, 0, 4, 5);
    EXPECT_NEAR(r.area(), 20.0, 1e-6);
}

// Тест для вычисления общей площади фигур в массиве
TEST(ArrayTest, TotalAreaCalculation) {
    Array<std::shared_ptr<Figure<int>>> figures;
    figures.add(std::make_shared<Triangle<int>>(0, 0, 3, 0, 0, 4));
    figures.add(std::make_shared<Square<int>>(0, 0, 5));
    figures.add(std::make_shared<Rectangle<int>>(0, 0, 4, 5));

    double totalArea = 0.0;
    for (size_t i = 0; i < figures.size(); ++i) {
        totalArea += static_cast<double>(*figures.get(i));
    }
    EXPECT_NEAR(totalArea, 6.0 + 25.0 + 20.0, 1e-6);
}

// Тест для проверки удаления фигуры из массива
TEST(ArrayTest, RemoveFigure) {
    Array<std::shared_ptr<Figure<int>>> figures;
    figures.add(std::make_shared<Triangle<int>>(0, 0, 3, 0, 0, 4));
    figures.add(std::make_shared<Square<int>>(0, 0, 5));
    figures.add(std::make_shared<Rectangle<int>>(0, 0, 4, 5));

    figures.remove(1); // Удаляем квадрат

    EXPECT_EQ(figures.size(), 2);
    double totalArea = 0.0;
    for (size_t i = 0; i < figures.size(); ++i) {
        totalArea += static_cast<double>(*figures.get(i));
    }
    EXPECT_NEAR(totalArea, 6.0 + 20.0, 1e-6);
}

// Тест для проверки копирования фигуры
TEST(TriangleTest, CopyFigure) {
    Triangle<int> t1(0, 0, 3, 0, 0, 4);
    std::shared_ptr<Figure<int>> t2 = t1.clone();

    EXPECT_TRUE(t1 == *t2);
}

// Тест для проверки перемещения фигуры
TEST(TriangleTest, MoveFigure) {
    Triangle<int> t1(0, 0, 3, 0, 0, 4);
    std::shared_ptr<Figure<int>> t2 = t1.move();

    EXPECT_TRUE(t1 == *t2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}