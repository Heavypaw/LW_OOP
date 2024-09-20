#include <gtest/gtest.h>
#include "func.hpp"


TEST(ProcessNumbersTest, basic_test_set) {
    int n = 1;
    int m = 3;
    int result = processNumbers(n, m);
    ASSERT_TRUE(result == 4);
}

TEST(ProcessNumbersTest_2, basic_test_set) {
    int n = -1;
    int m = 4;
    int result = processNumbers(n, m);
    ASSERT_TRUE(result == 5);
}


TEST(ProcessNumbersTest_3, basic_test_set) {
    int n = 5;
    int m = 3;
    int result = processNumbers(n, m);
    ASSERT_TRUE(result == 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
