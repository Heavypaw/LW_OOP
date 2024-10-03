#include <gtest/gtest.h>
#include "Decimal.h"

TEST(DecimalTest, DefaultConstructor) {
    Decimal d;
    ASSERT_EQ(d.toString(), "0");
}

TEST(DecimalTest, StringConstructor) {
    Decimal d("12345678901234567890");
    ASSERT_EQ(d.toString(), "12345678901234567890");
}

TEST(DecimalTest, CopyConstructor) {
    Decimal d1("12345678901234567890");
    Decimal d2(d1);
    ASSERT_EQ(d2.toString(), "12345678901234567890");
}

TEST(DecimalTest, MoveConstructor) {
    Decimal d1("12345678901234567890");
    Decimal d2(std::move(d1));
    ASSERT_EQ(d2.toString(), "12345678901234567890");
}

TEST(DecimalTest, Addition) {
    Decimal d1("12345678901234567890");
    Decimal d2("98765432109876543210");
    Decimal sum = d1 + d2;
    ASSERT_EQ(sum.toString(), "111111111011111111100");
}

TEST(DecimalTest, Subtraction) {
    Decimal d1("98765432109876543210");
    Decimal d2("12345678901234567890");
    Decimal diff = d1 - d2;
    ASSERT_EQ(diff.toString(), "86419753208641975320");
}

TEST(DecimalTest, AdditionAssignment) {
    Decimal d1("12345678901234567890");
    Decimal d2("98765432109876543210");
    d1 += d2;
    ASSERT_EQ(d1.toString(), "111111111011111111100");
}

TEST(DecimalTest, SubtractionAssignment) {
    Decimal d1("98765432109876543210");
    Decimal d2("12345678901234567890");
    d1 -= d2;
    ASSERT_EQ(d1.toString(), "86419753208641975320");
}

TEST(DecimalTest, Equality) {
    Decimal d1("12345678901234567890");
    Decimal d2("12345678901234567890");
    ASSERT_TRUE(d1 == d2);
}

TEST(DecimalTest, Inequality) {
    Decimal d1("12345678901234567890");
    Decimal d2("98765432109876543210");
    ASSERT_TRUE(d1 != d2);
}

TEST(DecimalTest, LessThan) {
    Decimal d1("12345678901234567890");
    Decimal d2("98765432109876543210");
    ASSERT_TRUE(d1 < d2);
}

TEST(DecimalTest, GreaterThan) {
    Decimal d1("98765432109876543210");
    Decimal d2("12345678901234567890");
    ASSERT_TRUE(d1 > d2);
}

TEST(DecimalTest, LessThanOrEqual) {
    Decimal d1("12345678901234567890");
    Decimal d2("98765432109876543210");
    ASSERT_TRUE(d1 <= d2);
}

TEST(DecimalTest, GreaterThanOrEqual) {
    Decimal d1("98765432109876543210");
    Decimal d2("12345678901234567890");
    ASSERT_TRUE(d1 >= d2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
