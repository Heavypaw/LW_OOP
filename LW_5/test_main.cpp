#include <gtest/gtest.h>
#include "FixedBlockMemoryResource.h"
#include "DynamicArray.h"

TEST(FixedBlockMemoryResourceTest, BasicAllocation) {
    FixedBlockMemoryResource mr(1024);
    void* ptr = mr.allocate(128, 8);
    EXPECT_NE(ptr, nullptr);
    mr.deallocate(ptr, 128, 8);
}

TEST(FixedBlockMemoryResourceTest, MultipleAllocations) {
    FixedBlockMemoryResource mr(1024);
    void* ptr1 = mr.allocate(128, 8);
    void* ptr2 = mr.allocate(256, 8);
    EXPECT_NE(ptr1, nullptr);
    EXPECT_NE(ptr2, nullptr);
    EXPECT_NE(ptr1, ptr2);
    mr.deallocate(ptr1, 128, 8);
    mr.deallocate(ptr2, 256, 8);
}

TEST(DynamicArrayTest, BasicOperations) {
    FixedBlockMemoryResource mr(1024);
    DynamicArray<int> arr(&mr);

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    EXPECT_EQ(arr.size(), 3);
    EXPECT_EQ(arr.begin(), arr.begin());
    EXPECT_NE(arr.begin(), arr.end());

    int sum = 0;
    for (int value : arr) {
        sum += value;
    }
    EXPECT_EQ(sum, 6);
}

TEST(DynamicArrayTest, ComplexType) {
    struct ComplexType {
        int a;
        double b;
        std::string c;

        ComplexType(int a, double b, const std::string& c) : a(a), b(b), c(c) {}
    };

    FixedBlockMemoryResource mr(4096);
    DynamicArray<ComplexType> arr(&mr);

    arr.push_back(ComplexType(1, 2.0, "test"));
    arr.push_back(ComplexType(2, 3.0, "test2"));

    EXPECT_EQ(arr.size(), 2);
    EXPECT_EQ((*arr.begin()).a, 1);
    EXPECT_EQ((*arr.begin()).b, 2.0);
    EXPECT_EQ((*arr.begin()).c, "test");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}