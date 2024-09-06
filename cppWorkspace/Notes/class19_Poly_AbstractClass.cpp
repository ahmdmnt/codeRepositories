#include <iostream>

/*
Polymorphism and Function Overriding:
    - Abstract Class Rules:
        1. Allowed to create instance from abstract class.
        2. in the Inherited Class, It is not needed to override, in this case, i will use base function implementation.
        3. At least have one Implemented Function.
        4. It can have Also Pure Virtual Function.
*/

/********************************************************/
class Shape {           // INTERFACE CLASS
public:
    virtual void draw() {
        std::cout<< "This is A Shape" << std::endl;
    }
    virtual void test() = 0;
};

class Rectangle: public Shape {
    int pvHeight;
    int pvLength;
public:
    void test() override {
        std::cout<< "rect test" << std::endl;
    }
};

class Triangle: public Shape {
    int pvHeight;
public:
    void draw() override {
        std::cout<< "This is A Triangle" << std::endl;
    }
    void test() override {
        std::cout<< "tri test" << std::endl;
    }
};
/****************************************************************************/  

int main() {
    
    Rectangle rectangleInstance;
    rectangleInstance.draw();           // not Overrided.
    rectangleInstance.test();           // Overrided.

    Triangle triangleInstance;
    triangleInstance.draw();            // Overrided.
    triangleInstance.test();           // Overrided.

    return 0;
}
