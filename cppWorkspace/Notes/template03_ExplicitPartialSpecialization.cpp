#include <iostream>
#include <memory>
#include <cstdio>

/*
    Template Class - Primary Template
*/
template<typename T, typename U> class myContaniner {
public:
    T value_1;
    U value_2;
    myContaniner(T l_val1, U l_val2): value_1(l_val1), value_2(l_val2) {
        std::cout << "Primary Template" << std::endl;
    }
    void print() {
        std::cout << "Value 1: " << value_1 << std::endl; 
        std::cout << "Value 2: " << value_2 << std::endl; 
        std::cout << "-----------------------" << std::endl;  
    }
};

/*
    Partial Specialization 1.
*/
template<typename T> class myContaniner<T, T> {
public:
    T value_1;
    T value_2;
    myContaniner(T l_val1, T l_val2): value_1(l_val1), value_2(l_val2) {
        std::cout << "Partial Specialization 1" << std::endl;
    }
    void print() {
        std::cout << "Value 1: " << value_1 << std::endl; 
        std::cout << "Value 2: " << value_2 << std::endl; 
        std::cout << "-----------------------" << std::endl;  
    }
};

/*
    Partial Specialization 2.
*/
template<typename T> class myContaniner<T, int> {
public:
    T value_1;
    int value_2;
    myContaniner(T l_val1, T l_val2): value_1(l_val1), value_2(l_val2) {
        std::cout << "Partial Specialization 2" << std::endl;
    }
    void print() {
        std::cout << "Value 1: " << value_1 << std::endl; 
        std::cout << "Value 2: " << value_2 << std::endl; 
        std::cout << "-----------------------" << std::endl;  
    }
};

/*
    Explicit Specialization.
*/
template<> class myContaniner<double, double> {
public:
    double value_1;
    double value_2;
    myContaniner(double l_val1, double l_val2): value_1(l_val1), value_2(l_val2) {
        std::cout << "Explicit Specialization" << std::endl;
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
        Primary Template
    */
    myContaniner<int, double> containerInstance1(5, 1.5);
    containerInstance1.print();

    /*
        Partial Specialization 1
    */
    myContaniner<float, float> containerInstance2(5.5, 6.2);
    containerInstance2.print();

    /*
        Partial Specialization 2
    */
    myContaniner<double, int> containerInstance3(5.5, 6);
    containerInstance3.print();

    /*
        Explicit Specialization
    */
    myContaniner<double, double> containerInstance4(2.5, 2.5);
    containerInstance4.print();


    return 0;
}
