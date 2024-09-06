#include <iostream>

/*
Inheritance:
|   Base Visiblity      |           Derived Visiblilty                  |
+-----------------------+-----------------------------------------------+
|                       |   Public      |   Protected   |   Private     |
+-----------------------+---------------+---------------+---------------+
|   Public              |   Public      |   Protected   |   Private     |
|   Protected           |   Protected   |   Protected   |   Private     |
|   Private             |   No Inherted |   No Inherted |   No Inherted |
+-----------------------+---------------+---------------+---------------+

    1- Derived inherited Base as PUBLIC:    class Derived : public Base { .. }
        - public    -> public
        - protected -> protected
        - private   -> Not inherited
    
    2- Derived inherited Base as PROTECTED: class Derived : protected Base { .. }
        - public    -> protected
        - protected -> protected
        - private   -> Not inherited

    3- Derived inherited Base as PRIVATE: class Derived : private Base { .. }
        - public    -> private
        - protected -> private
        - private   -> Not inherited

    NOTE: 
    - private IS NOT seen from base ... how to be able to see it in Derived??
    -- when i use friend method/class.

    - Use of Protected Keyword?
    -- to give ability to be private not used by objects but available only in inheritence.
*/

/********************************************************/
class Base {
    int pv_Data;

public:
    Base(int data) : pv_Data(data) {}
    void publicFun(void) { std::cout << "Base_publicFun: " << pv_Data << std::endl; }
protected:
    void protectedFun(void) { std::cout << "Base_protectedFun: " << pv_Data << std::endl; }
private:
    void privateFun(void) { std::cout << "Base_privateFun: " << pv_Data << std::endl; }
};


/**
 *      1. Child inherits Public Base
 */
class childPublicBase: public Base {
public:
    childPublicBase(int data) : Base(data) {}
    void print() {
        std::cout << "1. Child inherits Public Base" << std::endl;
        publicFun();
        protectedFun();
        // privateFun();        // Error: Not Inherited..
        std::cout << "" << std::endl;
    }
};

/**
 *      2. Child inherits Protected Base
 */
class childProtectedBase: protected Base {
public:
    childProtectedBase(int data) : Base(data) {}
    void print() {
        std::cout << "2. Child inherits Protected Base" << std::endl;
        publicFun();
        protectedFun();
        // privateFun();        // Error: Not Inherited..
        std::cout << "" << std::endl;
    }
};

/**
 *      3. Child inherits Private Base
 */
class childPrivateBase: private Base {
public:
    childPrivateBase(int data) : Base(data) {}
    void print() {
        std::cout << "3. Child inherits Private Base" << std::endl;
        publicFun();
        protectedFun();
        // privateFun();        // Error: Not Inherited..
        std::cout << "" << std::endl;
    }
};


/**
 *      4. Grandchild inherits public Child inherits Protected Base
 */
class Grandchild_1: public childProtectedBase {
public:
    Grandchild_1(int data) : childProtectedBase(data) {}
    void print() {
        std::cout << "4. Grandchild inherits public Child inherits Protected Base" << std::endl;
        publicFun();            // Still seen from inside class even if double inherited.
        protectedFun();         // Still seen from inside class even if double inherited.
        // privateFun();        // Error: Not Inherited from Base from beginning..
        std::cout << "" << std::endl;
    }
};


/**
 *      5. Grandchild inherits public Child inherits Private Base
 */
class Grandchild_2: public childPrivateBase {
public:
    Grandchild_2(int data) : childPrivateBase(data) {}
    void print() {
        std::cout << "5. Grandchild inherits public Child inherits Private Base" << std::endl;
        // publicFun();         // Private method in childPrivateBase, however it was Public in Base
        // protectedFun();      // Private method in childPrivateBase, however it was Public in Base
        // privateFun();        // Error: Not Inherited from Base from beginning..
        std::cout << "" << std::endl;
    }
};

/****************************************************************************/

int main() {
    
    childPublicBase child1(100);
    child1.publicFun();
    child1.print();
    // child1.protectedFun();      // Error: Used only inside the Derived Class not here..


    childProtectedBase child2(200);
    child2.print();
    // child2.publicFun();         // Error: Used only inside the Derived Class not here.. all Base methods are conveted to protected.
    // child2.protectedFun();      // Error: Used only inside the Derived Class not here.. 

    childPrivateBase child3(300);
    child3.print();
    // child3.publicFun();         // Error: Used only inside the Derived Class not here.. all Base methods are conveted to private.
    // child3.protectedFun();      // Error: Used only inside the Derived Class not here.. 

    Grandchild_1 Grandchild1(400);
    Grandchild1.print();

    Grandchild_2 Grandchild2(500);
    Grandchild1.print();

    return 0;
}
