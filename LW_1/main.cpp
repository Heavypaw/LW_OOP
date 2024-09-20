#include <iostream>
#include "func.hpp"

int main() {
    int startNum, endNum;

    std::cout << "Введите начальное число: ";
    std::cin >> startNum;
    std::cout << "Введите конечное число: ";
    std::cin >> endNum;

    int result = processNumbers(startNum, endNum);
    std::cout << result;
    return 0;
}
