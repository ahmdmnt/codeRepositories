#include <iostream>
#include <vector>

int mul(int a, int b=0);        //default parameters are set in last args in prototype      
float mul(float a, float b);

int main() {
    
   std::cout<< mul(1, 2) << std::endl;
   std::cout<< mul(1.4f, 2.1f) << std::endl;

    return 0;
}

//Function Overloading (mangle feature) -- BUT I HAVE TO SEND CORRECT ARGUMENT TYPE
int mul(int a, int b) {
    return a*b;
}

float mul(float a, float b) {
    return a*b;
}