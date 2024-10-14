#include <gtest/gtest.h>
#include "Decimal.h"

TEST(DecimalTest, DefaultConstructor) {
    Decimal d;
    EXPECT_EQ(d.toString(), "0");
}

TEST(DecimalTest, ConstructorFromULL) {
    Decimal d(12345678901234567890ULL);
    EXPECT_EQ(d.toString(), "12345678901234567890");
}

TEST(DecimalTest, ConstructorFromString) {
    Decimal d("12345678901234567890");
    EXPECT_EQ(d.toString(), "12345678901234567890");
}

TEST(DecimalTest, CopyConstructor) {
    Decimal d1("12345678901234567890");
    Decimal d2(d1);
    EXPECT_EQ(d2.toString(), "12345678901234567890");
}

TEST(DecimalTest, AssignmentOperator) {
    Decimal d1("12345678901234567890");
    Decimal d2;
    d2 = d1;
    EXPECT_EQ(d2.toString(), "12345678901234567890");
}

TEST(DecimalTest, AdditionOperator) {
    Decimal d1("12345678901234567890");
    Decimal d2("98765432109876543210");
    Decimal result = d1 + d2;
    EXPECT_EQ(result.toString(), "111111111011111111100");
}

TEST(DecimalTest, SubtractionOperator) {
    Decimal d1("98765432109876543210");
    Decimal d2("12345678901234567890");
    Decimal result = d1 - d2;
    EXPECT_EQ(result.toString(), "86419753208641975320");
}

TEST(DecimalTest, AdditionAssignmentOperator) {
    Decimal d1("12345678901234567890");
    Decimal d2("98765432109876543210");
    d1 += d2;
    EXPECT_EQ(d1.toString(), "111111111011111111100");
}

TEST(DecimalTest, SubtractionAssignmentOperator) {
    Decimal d1("98765432109876543210");
    Decimal d2("12345678901234567890");
    d1 -= d2;
    EXPECT_EQ(d1.toString(), "86419753208641975320");
}

TEST(DecimalTest, EqualityOperator) {
    Decimal d1("12345678901234567890");
    Decimal d2("12345678901234567890");
    EXPECT_TRUE(d1 == d2);
}

TEST(DecimalTest, InequalityOperator) {
    Decimal d1("12345678901234567890");
    Decimal d2("98765432109876543210");
    EXPECT_TRUE(d1 != d2);
}

TEST(DecimalTest, LessThanOperator) {
    Decimal d1("12345678901234567890");
    Decimal d2("98765432109876543210");
    EXPECT_TRUE(d1 < d2);
}

TEST(DecimalTest, GreaterThanOperator) {
    Decimal d1("98765432109876543210");
    Decimal d2("12345678901234567890");
    EXPECT_TRUE(d1 > d2);
}

TEST(DecimalTest, LessThanOrEqualOperator) {
    Decimal d1("12345678901234567890");
    Decimal d2("98765432109876543210");
    EXPECT_TRUE(d1 <= d2);
}

TEST(DecimalTest, GreaterThanOrEqualOperator) {
    Decimal d1("98765432109876543210");
    Decimal d2("12345678901234567890");
    EXPECT_TRUE(d1 >= d2);
}

TEST(DecimalTest, InputOperator) {
    Decimal d;
    std::istringstream iss("12345678901234567890");
    iss >> d;
    EXPECT_EQ(d.toString(), "12345678901234567890");
}

TEST(DecimalTest, OutputOperator) {
    Decimal d("12345678901234567890");
    std::ostringstream oss;
    oss << d;
    EXPECT_EQ(oss.str(), "12345678901234567890");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
