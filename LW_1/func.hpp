#include <iostream>
#include <list>
#include <bitset>

int processNumbers(int startNum, int endNum) {
    std::list<std::string> binaryList; 
    int totalOnes = 0;

    if (startNum >= endNum || startNum < 0 || endNum < 0) {
        std::cout << "Неверные значения переменных" << std::endl;
        return -1;
    }

   
    for (int i = startNum; i <= endNum; i++) {
        std::bitset<32> binary(i);
        binaryList.push_back(binary.to_string());

    
        totalOnes += binary.count();
    }

   

    return totalOnes; 
}
