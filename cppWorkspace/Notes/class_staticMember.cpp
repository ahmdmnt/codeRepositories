#include <iostream>

/*
Static Member
    - not related to certain object, it is related to class itself.
    - can be accessed from either class name or object/instance name.
        object.staticMember
        class::staticMember
    - Normal const member can be initialized in initializer list "constructor"
        - static const member CAN NOT BE init in constructor

Static Method
    - not related to certain object, it is related to class itself.
    - not access to normal Member (no access to this->VAR)... ONLY STATIC
*/

/********************************************************/
class Data {
private:
    int priv;
    const int constData;

public:
    const static int staConst1 = 50;     // ISO C++ in-class init of non-const static member (ONLY INTEGRAL) // (no ref .. not in Mem) - compiler replace var with value
    const static int staConst2;         // ISO C++ out-class init of non-const static member 
    static int staData;                 // ISO C++ forbids in-class initialization of non-const static member
    int pub= 0;
    Data(int num1, int num2) : priv(num1) , constData(num2) {}      //static const member CAN NOT BE init in constructor
    void print(void);
    static void printStaticData(void);
};
void Data::print(void) {        
    std::cout<< "- Static Data= " << staData << std::endl;
    std::cout << " - privData: " << priv << std::endl;
    std::cout << "   - pubData: " << pub << std::endl;
};
void Data::printStaticData(void) {      
    staData = 123456;       // OK TO ACCESS/MODIFY
    // pub = 10;               // ERROR TO ACCESS/MODIFY 
    std::cout<< "- staData: " << staData << std::endl;
    std::cout<< "- staConst1: " << staConst1 << std::endl;
    std::cout<< "- staConst2: " << staConst2 << std::endl;
};

int Data::staData = 123;            // Initailization of Static Member data.
const int Data::staConst2 = 20;     // (.rodata) Initailization of Const Static Member data (INTEGRAL AND NON-INTEGRAL TYPES).
/********************************************************/

int main() {
    Data data(500, 11);                // Aggregation Constructor/Initailization "NOT A Good Practice"
    data.print();
    
    std::cout<< "- Static Data= " << data.staData << std::endl;
    std::cout<< "- Static Constant1= " << Data::staConst1 << std::endl;
    std::cout<< "- Static Constant2= " << data.staConst2 << std::endl;
    
    Data::printStaticData();

    return 0;
}