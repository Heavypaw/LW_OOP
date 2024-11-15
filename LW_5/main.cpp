#include "DynamicArray.h"
#include "FixedBlockMemoryResource.h"
#include <iostream>

int main() {
    FixedBlockMemoryResource mr(1024);
    DynamicArray<int> arr(&mr);

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    for (int value : arr) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}