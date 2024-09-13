#include <iostream>

/*
Dynamic Casting
    - Works in Runtime, return Nullptr in runtime if casting can not be done.
    - I Can Assign Parent Pointer to Derived Class ... That pointer will see all members available in Parent only not all members in derived.
    - Dynamic Cast for Parent Pointer >> will make basePtr content casted to childPtr
    - Issue represented below.
*/

/********************************************************/
class Base {
public:
    virtual void print() {
        std::cout<< "Printing" << std::endl;
    }
};

class Derived_1: public Base {
public:
    void print() override {
        std::cout<< "Printing Child 1" << std::endl;
    }
    void scan() {
        std::cout<< "Scanning Child 1" << std::endl;
    }
};
class Derived_2: public Base {
public:
    void print() override {
        std::cout<< "Printing Child 2" << std::endl;
    }
    void fetch() {
        std::cout<< "Fetching Child 1" << std::endl;
    }
};
/****************************************************************************/  

int main() {
    
    Base *ptrBase = new Derived_1();            // I can create a Base Pointer and Point to child class
    ptrBase->print();
    // ptrBase->scan();                            // but i cant point to members/methods not in the Base.  Solution below (Dynamic Cast)

    Derived_1* ptrDerived1 = dynamic_cast<Derived_1*>(ptrBase);         // Becuz the pointer was for Parent Class it can be casted to child.
    if(ptrDerived1) {                                                   // (Dynamic Cast) if Error occurs in Init .. it will return nullptr
        ptrDerived1->scan();
    }


    Derived_2* ptrDerived2 = dynamic_cast<Derived_2*>(ptrBase);         // ptrBase is pointing to Dervied1 which can't be casted to Derived 2 ... Error > will normallu compile but will ret NULL_PTR
    if(ptrDerived2) {                                                   // (Dynamic Cast) if Error occurs in Init .. it will return nullptr
        ptrDerived2->fetch();                                           // Won;t be entered in this case
    }

    return 0;
}
