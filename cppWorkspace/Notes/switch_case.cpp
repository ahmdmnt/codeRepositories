#include <iostream>

int main() {
    int i = 0;

    const int value = 10;

    switch(i) {
        case value:     // 1- const in switch case is OK
            std::cout<< "value= " << value << std::endl;
        break;
        default: {      // 2- brackets in switch case to define var in scope
            int x = 5;
            std::cout<< "x = " << x << std::endl;
        }
        break;
    }

    return 0;
}