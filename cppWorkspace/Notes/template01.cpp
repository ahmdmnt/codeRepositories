/*
    Template:
        Types:
        1. Template Class.
        2. Template Function.
*/
#include <iostream>
#include <memory>
#include <cstdio>
 
 /*
    Template Function:
    it is induction during compilation phase.
    same Implementation but generic type.
        auto deduction in C++14

Define template with single arguments definition
 */
template<typename T>
T division(T x, T y) {
    return x/y;
}

/*
Define template with two multiple arguments definition
*/
template<typename T, typename U>
auto multiple(T x, U y) -> decltype(x/y) {      // Return type is declared from return type [-> decltype(x/y)] "!!NOT MANDATORY!!"
// auto multiple(T x, U y) {
    return x*y;
}


/*
Template Class - Generic type also
    auto deduction in C++17
*/
template<typename T> class myContaniner {
public:
    T value;
    myContaniner(T l_val): value(l_val) {}
    void print() {
        std::cout << "Value: " << value << std::endl;  
    }
    template<typename U>
    void add(U extra_value) {
        value += extra_value;
    }
};

int main() {

    /*
    Define three different function according to datetype
    */
    std::cout << division(3, 2) << std::endl;
    std::cout << division(3.0, 2.0) << std::endl;
    std::cout << division(3.0f, 2.0f) << std::endl;

    std::cout << multiple(3.0f, 2) << std::endl;

    myContaniner containerInstance1(10);                // Template Class:  Auto deduction in c++17       
    containerInstance1.print();

    myContaniner<std::string> containerInstance2("Ahmed");  // Add type by myself
    containerInstance2.print();

    containerInstance1.add(30);                          // Template FunctioN: Auto deduction in c++14
    containerInstance1.print();

    containerInstance2.add<std::string>("Montasser");   // Add type by myself
    containerInstance2.print();

    return 0;
}
