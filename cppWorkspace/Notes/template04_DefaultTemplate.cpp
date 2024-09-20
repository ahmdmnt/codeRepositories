#include <iostream>
#include <memory>
#include <cstdio>

/*
    Template Class - Default Template
        I can set a Default Datatype, if not entered explicitly
*/
template<typename T, typename U = int> class myContaniner {
public:
    T value_1;
    U value_2;
    myContaniner(T l_val1, U l_val2): value_1(l_val1), value_2(l_val2) {
    }
    void print() {
        std::cout << "Value 1: " << value_1 << std::endl; 
        std::cout << "Value 2: " << value_2 << std::endl; 
        std::cout << "-----------------------" << std::endl;  
    }
};


int main() {
    std::cout << "-----------------------" << std::endl; 
    /*
        Default Template
    */
    myContaniner<int> containerInstance1(5, 2.5);   // 2nd Argument datatype is not entered, so it will consider it as default = int (Casting occured)
    containerInstance1.print();

    myContaniner<int, double> containerInstance2(5, 2.5);   // Override default typename U datatype
    containerInstance2.print();

    return 0;
}
