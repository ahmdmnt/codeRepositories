#include <iostream>
#include <vector>

int mul(int a, int b=0);        //default parameters are set in last args in prototype      
float mul(float a, float b);

int main() {
    int i = 0;

    const int value = 10;
    switch(i) {
        case value:     // 1- const in switch case
            std::cout<< "value= " << value << std::endl;
        break;
        default: {      // 2- brackets in switch case to define var in scope
            int x = 5;
            std::cout<< "x = " << x << std::endl;
        }
        break;
    }

    // 3- Vectors
    std::vector<int> numList{10, 11, 12, 13, 14, 15};
    // 4- Ranged-base for Loop
    for(auto itr: numList) {        // 5- auto ,, automatic detect datatype 
        std::cout << itr << " ";
    } 
    std::cout<< std::endl;

    // Heap and Dynamic Memory allocation
    int *intPtr = new int(10);      // Allocate and Initalize
    std::cout << *intPtr;           
    *intPtr = 45;                   // Set Data
    delete intPtr;                  // Delete allocated value
    intPtr = nullptr;               // Remove pointing address

    return 0;
}

//Function Overloading (mangle feature) -- BUT I HAVE TO SEND CORRECT ARGUMENT TYPE
int mul(int a, int b) {
    return a*b;
}

float mul(float a, float b) {
    return a*b;
}