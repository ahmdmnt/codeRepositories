#include <iostream>
#include <memory>
#include <cstdio>

/*
    Template Function - Variadic Arguments
        it is considered as "Multiple of Functions"
            similar to recusrive function, but it is actually calling MULTIPLE GENERATED functions created by compiler not calling itself multiple times.
*/

void printFu() {            // Closure of Variadic function if Args reaches 0
    std::cout <<  std::endl << "----------------------" << std::endl;
    std::cout << std::endl;
}

template <typename T, typename... Args>
void printFu(T variable, Args... args) {
    // std::cout << "Number of Args: " << sizeof...(args) << std::endl;
    std::cout << variable << " - ";
    printFu(args...);       // Call ANOTHER function with reset of args input values. "NOT RECURSION".
    /* when args reachs ... zero arg -> go to void printFu() <- {Closure function} */
}


int main() {
    /*
    Can accept variable number of arguments
    */
    printFu(1);
    printFu(1, 2.5);
    printFu(1, 2.5, "Ahmed");

    return 0;
}
