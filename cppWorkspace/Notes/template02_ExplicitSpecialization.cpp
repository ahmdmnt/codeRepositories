#include <iostream>
#include <memory>
#include <cstdio>

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

/*
Explicit Specialization
    - Go to if mentioning specific datatype ... not generic as above template
*/
template<> class myContaniner<float> {
    // I CAN EDIT AS I WANT IN THIS TEMPLATE regardless the above template
public:
    float value;
    myContaniner(float l_val): value(l_val) {}
    void print() {
        std::cout << "Value: " << value << std::endl;  
    }
    template<typename U>
    void add(U extra_value) {
        extra_value *= 2;
        value += extra_value;
    }
    template<typename U>
    void normalAdd(U extra_value) {
        value += extra_value;
    }
};


int main() {
    myContaniner containerInstance1(10);                // Template Class:  Auto deduction in c++17       
    containerInstance1.print();

    myContaniner<std::string> containerInstance2("Ahmed");  // Add type by myself
    containerInstance2.print();

    containerInstance1.add(30);                          // Template FunctioN: Auto deduction in c++14
    containerInstance1.print();

    containerInstance2.add<std::string>("Montasser");   // Add type by myself
    containerInstance2.print();


    /*
    Explicit Specialization
    */
    myContaniner<float> containerInstance3(5);        // will go to the Explicit template one
    containerInstance3.add<int>(1);
    containerInstance3.normalAdd<int>(1);
    containerInstance3.print();


    return 0;
}
