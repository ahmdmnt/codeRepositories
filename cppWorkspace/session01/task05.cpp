/*
 * Task 05:
 * Multiplication table
 */

#include <iostream>
#include <numeric>
#include <iomanip>
#include <vector>
#include <string>

int main() {

    int inputNum;
    std::cout<< "Enter desired Multiplication Table: ";
    std::cin>> inputNum;

    std::vector<int> mulTable(13);
    std::iota(mulTable.begin(), mulTable.end(), 0);
    std::string str;
    for(auto num: mulTable) {
        str = std::to_string(inputNum)+"x"+std::to_string(num);
        std::cout<< std::setw(5) << str << " = " << std::setw(3) << inputNum*num << std::endl;
    }
    return 0;
}