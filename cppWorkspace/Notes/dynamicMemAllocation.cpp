#include <iostream>
int main() {

    // Heap and Dynamic Memory allocation
    int *intPtr = new int(10);      // Allocate and Initalize
    std::cout << *intPtr;     

    *intPtr = 45;                   // Set Data
    delete intPtr;                  // Delete allocated value
    intPtr = nullptr;               // IMPORTANT: Remove pointing address

    return 0;
}