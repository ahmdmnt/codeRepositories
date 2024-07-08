/*
 * Task 03:
 * RIGHT angle triangle
 */

#include <iostream>
#include <cmath>

bool checkRightAngledTriangle(int H, int A, int B);

int main() {
    int A = 3;
    int B = 4;
    int H = 5;

    std::cout<< std::boolalpha;
    std::cout<< "Right Triangle: "<< checkRightAngledTriangle(H, A, B) << std::endl;
    return 0;
}

bool checkRightAngledTriangle(int H, int A, int B) {
    return (pow(H,2) == (pow(A,2)+pow(B,2)));
}