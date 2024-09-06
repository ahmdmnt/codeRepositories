#include <iostream>

/*
Polymorphism and Function Overriding:
    - Pure Virtual Function:
        Forcing the Derived Class, to define the Virtual Function...  (CPP Exclusive)
    
    - Interface Class Rules:
        1. Not allowed to create instance from interface class.
        2. in the Inherited Class, We MUST IMPLEMENT ALL Pure Virtual Functions.
        3. Doesn't have any Implemented Functions.

    override KEYWORD:
    is an [Optional] keyword, means that you are overriding PURE Virtual Function. 
    ,,, its Benefit: because it is used with VirtualFn, its distingsh between normal VirtualFn. 
    
    Readable Code
    virtual void fn() = 0;  -->> To Force override.
    void fn() override {    -->> To Indicate overriding.
    
*/

/********************************************************/
class Shape {           // INTERFACE CLASS
public:
    virtual void setHeight(int height) = 0;        // Pure Virtual Function -- No Definition here and Definition is forced in derived classes.
    virtual void draw() = 0;
};

class Rectangle: public Shape {
    int pvHeight;
    int pvLength;
public:
    void draw() override {
        std::cout<< "Rectangle Shape" << std::endl;
        std::cout<< "pvHeight: " << pvHeight << std::endl;
        std::cout<< std::endl;
    }
    void setHeight(int height) override {
        pvHeight = height;
    }
};

class Triangle: public Shape {
    int pvHeight;
public:
    void draw() override;
    void setHeight(int height) override;
};
void Triangle::draw() { 
    std::cout<< "Triangle Shape" << std::endl;
    std::cout<< "pvHeight: " << pvHeight << std::endl;
    std::cout<< std::endl;
}
void Triangle::setHeight(int height) {
    pvHeight = height;
}
/****************************************************************************/  

int main() {
    
    // Create Instance from Different Derived Objects
    Shape* shapePtr_Rectangle = new Rectangle();
    Shape* shapePtr_Triangle = new Triangle();

    // Call function for each derived Object
    shapePtr_Rectangle->draw();
    shapePtr_Triangle->draw();

    shapePtr_Triangle->setHeight(10);
    shapePtr_Rectangle->setHeight(5);

    // Cleanup Heap Memory
    delete shapePtr_Rectangle;
    delete shapePtr_Triangle;
    shapePtr_Rectangle = nullptr;
    shapePtr_Triangle = nullptr;

    return 0;
}
