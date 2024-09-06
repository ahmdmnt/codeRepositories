#include <iostream>

/*
Polymorphism and Function Overriding:
    - Polymorphism Definition:
        Pointer to the Base Class.
    - 

*/

/********************************************************/
class Base {
    int pv_BaseData;

public:
    virtual void print(void) {              // vtable: Virtual Table ->> Dynamic/Late binding. 
    std::cout << "  > Base" << std::endl;
    }
    void baseTest(void) {
    std::cout << "  > Base-test" << std::endl;
    }
};
class Child_1: public Base {
public:
    void print(void) {
    std::cout << "  > Child-1" << std::endl;
    }
};

class Child_2: public Base {
public:
    void print(void) {
    std::cout << "  > Child-2" << std::endl;
    }
    void childTest(void) {
    std::cout << "  > Child-test" << std::endl;
    }
};
/****************************************************************************/
class Datatype {
public:
    virtual void print(void) {              // vtable: Virtual Table ->> Dynamic/Late binding. 
    std::cout << "  > Datatype" << std::endl;
    }
};
class Float: public Datatype {
public:
    void print(void) {
    std::cout << "  > Float" << std::endl;
    }
};

class Int: public Datatype {
public:
    void print(void) {
    std::cout << "  > Int" << std::endl;
    }
};

/*********************************/
void fn_datatypePrint(Datatype* instance) {
    instance->print();
}
void fn_datatypePrint(Datatype& instance) {
    instance.print();
}
/****************************************************************************/


int main() {
    
    Base baseInstance;
    baseInstance.print();
    baseInstance.baseTest();

    Base* baseInstancePtr = nullptr;
    
    std::cout<< "Example1: Child_1 child1Instance;" << std::endl;
    Child_1 child1Instance;
    baseInstancePtr = &child1Instance;      // Assigning it to drived instance
    baseInstancePtr->print();               // Function Overriding
    baseInstancePtr->baseTest();
    std::cout<< std::endl;


    std::cout<< "Example2: Child_2 child2Instance;" << std::endl;
    Child_2 child2Instance;
    baseInstancePtr = &child2Instance;      // Change to new instance
    baseInstancePtr->print();               // Function Overriding
    baseInstancePtr->baseTest();
    std::cout<< std::endl;

    
    std::cout<< "Example3: Error Pointer to Base Class cannot see the Child Functions" << std::endl;
    // baseInstancePtr->childTest();        // Error Pointer to Base Class cannot see the Child Functions
    Child_2* childInstancePtr = (Child_2*)baseInstancePtr;
    childInstancePtr->print();               // Function Overriding
    childInstancePtr->baseTest();
    childInstancePtr->childTest();
    std::cout<< std::endl;


    std::cout<< "Example4: Usecase for Polymorphism using Pointer" << std::endl;
    fn_datatypePrint(new Float());          // Mem Leakage will Occur, cuz data not deleted.
    fn_datatypePrint(new Int());
    std::cout<< std::endl;


    std::cout<< "Example5: using Reference" << std::endl;
    Int intElement;
    Datatype *datatypePtr = &intElement;
    fn_datatypePrint(intElement);
    std::cout<< std::endl;

    return 0;
}
