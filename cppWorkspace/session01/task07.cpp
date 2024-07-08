/*
 * Task 07:
 * Change from decimal to binary and vice versa
 */

#include <iostream>
#include <bitset>
#include <ios>

int main() {

    int inputNum;
    std::cout<< "Enter a Number: ";
    std::cin>> inputNum;

    std::cout<< std::showbase;
    std::cout<< "Number in Bin format: " << std::bitset<16>{inputNum} << std::endl;
    std::cout<< "Number in Oct format: " << std::oct << inputNum << std::dec << std::endl;
    std::cout<< "Number in Hex format: " << std::hex << inputNum << std::dec << std::endl;   

    return 0;
}