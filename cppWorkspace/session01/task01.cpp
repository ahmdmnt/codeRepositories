/*
 * Task 01:
 * Create a table for ASCII code
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

int main() {

    std::vector<int> numList(26);
    std::iota(numList.begin(), numList.end(), 65);

    std::cout << "+--------+--------+" << std::endl;
    std::cout<< "|" << std::setw(8) << "Char" << "|";
    std::cout<< std::setw(8) << "ASCII" << "|" << std::endl;
    std::cout << "+--------+--------+" << std::endl;
    for(auto num: numList) {
        std::cout<< "|" << std::setw(8) << num << "|";
        std::cout<< std::setw(8) << char(num) << "|" << std::endl;
    }
    std::cout << "+--------+--------+" << std::endl;

    return 0; 
}