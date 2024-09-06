#include <iostream>

/*
Polymorphism and Function Overriding:
    - Polymorphism Definition:
        Pointer to the Base Class.
    - 

*/

/********************************************************/
class Shape {
public:
    virtual void draw(int length, int height) {              // vtable: Virtual Table ->> Dynamic/Late binding. 
    std::cout << "  > Please Specify the shape type" << std::endl;
    }
};
class Rectangle: public Shape {
public:
    void draw(int length, int height) {
        std::cout<< "Rectangle Shape" << std::endl;
        for (int i = 0; i < height; i++) {              // Loop through the height of the rectangle
            for (int j = 0; j < length; j++) {          // Loop through the length of the rectangle
                std::cout << "*";                       // Print asterisk
            }
            std::cout << std::endl;                     // Move to the next line
        }
        std::cout << std::endl;
    }
};

class Triangle: public Shape {
public:
    void draw(int length, int height) { 
        std::cout<< "Triangle Shape" << std::endl;
        for (int i = 1; i <= height; i++) {         // Loop through each line to print the triangle
            for (int j = 1; j <= i; j++) {          // Print asterisks equal to the current line number
                std::cout << "*";
            }
            std::cout << std::endl;                 // Move to the next line
        }
        std::cout << std::endl;
    }
};
/****************************************************************************/  

int main() {
    
    // Create Instance from Different Derived Objects
    Shape* shapePtr_Rectangle = new Rectangle();
    Shape* shapePtr_Triangle = new Triangle();

    // Call function for each derived Object
    shapePtr_Rectangle->draw(8, 5);
    shapePtr_Triangle->draw(0, 5);

    // Cleanup Heap Memory
    delete shapePtr_Rectangle;
    delete shapePtr_Triangle;
    shapePtr_Rectangle = nullptr;
    shapePtr_Triangle = nullptr;

    return 0;
}
