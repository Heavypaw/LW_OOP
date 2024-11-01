#include <gtest/gtest.h>
#include "figure.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"
#include "array.h"

TEST(TriangleTest, AreaCalculation) {
    Triangle t(0, 0, 3, 0, 0, 4);
    EXPECT_NEAR(t.area(), 6.0, 1e-6);
}

TEST(SquareTest, AreaCalculation) {
    Square s(0, 0, 5);
    EXPECT_NEAR(s.area(), 25.0, 1e-6);
}

TEST(RectangleTest, AreaCalculation) {
    Rectangle r(0, 0, 4, 5);
    EXPECT_NEAR(r.area(), 20.0, 1e-6);
}

TEST(ArrayTest, TotalAreaCalculation) {
    Array figures;
    figures.add(new Triangle(0, 0, 3, 0, 0, 4));
    figures.add(new Square(0, 0, 5));
    figures.add(new Rectangle(0, 0, 4, 5));

    EXPECT_NEAR(figures.totalArea(), 6.0 + 25.0 + 20.0, 1e-6);
}

TEST(ArrayTest, RemoveFigure) {
    Array figures;
    figures.add(new Triangle(0, 0, 3, 0, 0, 4));
    figures.add(new Square(0, 0, 5));
    figures.add(new Rectangle(0, 0, 4, 5));

    figures.remove(1); 

    EXPECT_EQ(figures.size(), 2);
    EXPECT_NEAR(figures.totalArea(), 6.0 + 20.0, 1e-6);
}

TEST(TriangleTest, CopyFigure) {
    Triangle t1(0, 0, 3, 0, 0, 4);
    Triangle* t2 = t1.clone();

    EXPECT_TRUE(t1 == *t2);
    delete t2;
}

TEST(TriangleTest, MoveFigure) {
    Triangle t1(0, 0, 3, 0, 0, 4);
    Triangle* t2 = t1.move();

    EXPECT_TRUE(t1 == *t2);
    delete t2;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
