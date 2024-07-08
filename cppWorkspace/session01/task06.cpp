/*
 * Task 06:
 * Summation the digits of integer entered by user
 */

#include <iostream>

int main() {
    int inputNum;
    std::cout<< "Enter a Number: ";
    std::cin>> inputNum;

    int sumResult = 0;
    while(inputNum%10 != 0) {
        sumResult += inputNum%10;
        inputNum /= 10;
    }
    std::cout<< "Sum of digits = " << sumResult << std::endl;

    return 0;
}