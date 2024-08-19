#include <iostream>

/*
Inheritance:
    - Multiple.
    - Hybrid.
*/

/********************************************************/
class Base1 {
    int pv_Data1;

public:
    Base1(int data) : pv_Data1(data) {std::cout<< ">> Base1 Constructor" << std::endl;} 
    Base1() {std::cout<< ">> Base1 Default Constructor" << std::endl;}
    ~Base1() {std::cout<< ">> Base1 Destructor" << std::endl;}

    void print(void) {
    std::cout << "    - Base1.pv_Data1: " << pv_Data1 << std::endl;
    }
};
class Base2 {
    int pv_Data2;

public:
    Base2(int data) : pv_Data2(data) {std::cout<< ">> Base2 Constructor" << std::endl;} 
    Base2() {std::cout<< ">> Base2 Default Constructor" << std::endl;}
    ~Base2() {std::cout<< ">> Base2 Destructor" << std::endl;}

    void print(void) {
    std::cout << "    - Base2.pv_Data2: " << pv_Data2 << std::endl;
    }
};
class Base3 {
    int pv_Data3;

public:
    Base3(int data) : pv_Data3(data) {std::cout<< ">> Base3 Constructor" << std::endl;} 
    Base3() {std::cout<< ">> Base3 Default Constructor" << std::endl;}
    ~Base3() {std::cout<< ">> Base3 Destructor" << std::endl;}

    void print(void) {
    std::cout << "    - Base3.pv_Data3: " << pv_Data3 << std::endl;
    }
};
/****************************************************************************/


/**
 *    4. Multiple Inheritance (MISRA RULE: FORBIDDEN)
 *      Base 1 , Base 2 > Child 
 */
class Child1: public Base1, public Base2 {
public:
    Child1() {std::cout<< ">> Derived Default Constructor" << std::endl;}
    ~Child1() {std::cout<< ">> Derived Destructor" << std::endl;}
};
/****************************************************************************/

/**
 *    5.1. Hybrid Inheritance  (MISRA RULE: FORBIDDEN)
 *      Base > Child 1 , Child 2 > Grandchild
 *          -- USING Scope Resolution -- 
 */
class Child2: public Base3 {
public:
    Child2(int data) : Base3(data) {}
    Child2() {std::cout<< ">> Derived Default Constructor" << std::endl;}
    ~Child2() {std::cout<< ">> Derived Destructor" << std::endl;}
};

class Child3: public Base3 {
public:
    // Child3(int data) : Base3(data) {}
    Child3() {std::cout<< ">> Derived Default Constructor" << std::endl;}
    ~Child3() {std::cout<< ">> Derived Destructor" << std::endl;}
};


class GrandChild: public Child2, public Child3 {
public:
    GrandChild(int data) : Child2(data) /*, Child3(data)*/ {}
    GrandChild() {std::cout<< ">> Derived Derived Default Constructor" << std::endl;}
    ~GrandChild() {std::cout<< ">> Derived Derived Destructor" << std::endl;}
};
/****************************************************************************/


/**
 *    5.2. Hybrid Inheritance  (MISRA RULE: FORBIDDEN)
 *      Base > Child 1 , Child 2 > Grandchild
 *          -- USING virtual KEYWORD -- 
 */
class Child4: virtual public Base3 {
public:
    Child4() {std::cout<< ">> Derived Default Constructor" << std::endl;}
    ~Child4() {std::cout<< ">> Derived Destructor" << std::endl;}
};

class Child5: virtual public Base3 {
public:
    Child5() {std::cout<< ">> Derived Default Constructor" << std::endl;}
    ~Child5() {std::cout<< ">> Derived Destructor" << std::endl;}
};


class GrandChild2: public Child4, public Child5 {
public:
    GrandChild2() {std::cout<< ">> Derived Derived Default Constructor" << std::endl;}
    ~GrandChild2() {std::cout<< ">> Derived Derived Destructor" << std::endl;}
};
/****************************************************************************/

/********************************************************/

int main() {
    /**
    Multiple Inheritance calling different function.
        [[NOT STATIC FUNTION]] ... it is just used with Base1 (Class name) ONLY to be able to call it.
    */
    Child1 childInstance;

    childInstance.Base1::print();
    childInstance.Base2::print();


    /**
    Hybrid Inheritance calling different function.
        -- USING Scope Resolution --   
    */
    GrandChild grandChildInstance(123);

 // grandChildInstance.Base3::print();        // ERROR: 'Base3' is an ambiguous base of 'GrandChild'  - Can't know from which way it can reach Base3 from Child2, or Child3
    grandChildInstance.Child2::print();       // OK >> reaching Base3 through Child2
    grandChildInstance.Child3::print();       // OK >> reaching Base3 through Child3


    /**
    Hybrid Inheritance calling different function.
        -- USING virtual KEYWORD --   
    */
    GrandChild2 grandChildInstance2;
    grandChildInstance2.print();

    return 0;
}
