#include <iostream>

/*
Inheritance:
    - Single.
    - Multi-level.
    - Hierarchial
*/

/********************************************************/
class Data {
    std::string pv_String;
    int pv_Data;

public:
    Data(std::string l_string, int data) : pv_String(l_string), pv_Data(data) {std::cout<< ">> Base Constructor" << std::endl;} 
    Data() {std::cout<< ">> Base Default Constructor" << std::endl;}
    ~Data() {std::cout<< ">> Base Destructor" << std::endl;}

    void print(void) {        
    std::cout << "    - pv_String: " << pv_String << std::endl;
    std::cout << "    - pv_Data: " << pv_Data << std::endl;
    }
};

/**
 *    1. Single Inheritance
 */
class derivedData: public Data {
public:
    derivedData(std::string l_string, int data) : Data(l_string, data) {std::cout<< ">> Derived Constructor" << std::endl;}
    derivedData() {std::cout<< ">> Derived Default Constructor" << std::endl;}
    ~derivedData() {std::cout<< ">> Derived Destructor" << std::endl;}
};

/**
 *    2. Hierarchial Inheritance
 *      Multiple Single Inherit the same base Class.
 */
class derivedData1: public Data {
public:
    derivedData1(std::string l_string, int data) : Data(l_string, data) {std::cout<< ">> Derived Constructor" << std::endl;}
    derivedData1() {std::cout<< ">> Derived Default Constructor" << std::endl;}
    ~derivedData1() {std::cout<< ">> Derived Destructor" << std::endl;}
};


/**
 *    3. Multi-Level Inheritance
 */
class derivedDerivedData: public derivedData {
public:
    derivedDerivedData(std::string l_string, int data) : derivedData(l_string, data) {std::cout<< ">> Derived Derived Constructor" << std::endl;}
    derivedDerivedData() {std::cout<< ">> Derived Derived Default Constructor" << std::endl;}
    ~derivedDerivedData() {std::cout<< ">> Derived Derived Destructor" << std::endl;}
};
/********************************************************/

int main() {

    derivedData dD1;
    derivedData dD2("Ahmed", 123);

    dD1.print();
    std::cout<< "    --------------------------" << std::endl;
    dD2.print();

    std::cout<< "--------------------------" << std::endl;
    std::cout<< "--------------------------" << std::endl;
    derivedDerivedData ddD;
    ddD.print();

    return 0;
}
