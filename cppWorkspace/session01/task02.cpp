/*
 * Task 02:
 * Maximum number between three values
 */

#include<algorithm> 
#include <iostream>

int main() {
    int num1 = 10;
    int num2 = 100;
    int num3 = 5;

    std::cout << "Maximum value = " << std::max(std::max(num1, num2), num3) << std::endl;
    return 0;
}