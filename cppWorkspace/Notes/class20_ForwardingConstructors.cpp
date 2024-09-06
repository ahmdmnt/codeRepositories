#include <iostream>

/*
Forward ALL Constructors to dervied Class
    > using Base::Base
*/

/********************************************************/
class Base {
    int pvData1;
    int pvData2;
public:
    Base(int data) : pvData1(data) { 
        std::cout<< "Paramatized Constructor 1" << std::endl;
        std::cout<< "pvData1: " << pvData1 << std::endl;
    }
    Base(int data1, int data2) : pvData1(data1), pvData2(data2) {
        std::cout<< "Paramatized Constructor 2" << std::endl;
        std::cout<< "pvData1: " << pvData1 << std::endl;
        std::cout<< "pvData2: " << pvData2 << std::endl;
    }
};

class Derived: public Base {
public:
    using Base::Base;           // Forwarding All Base Constructors to this Derived Class ,,, without the need to type it again..
};
/****************************************************************************/  

int main() {
    
    Derived derivedInstance1(5);
    Derived derivedInstance2(5, 10);

    return 0;
}
