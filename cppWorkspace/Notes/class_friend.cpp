#include <iostream>

/*
Friend Class
    - Give ability to a Class to access all private members from the hosting class

Friend Function
    - Give ability to a Function to access all private members from the hosting class
*/

/********************************************************/
/*
NOTE:
Some times defining a class friend raise warning in compilers the the friend class is not declared yet.
    Solution >> Forwarding Declaration
*/  
class Temp;           // Forwarding Declaration
// void function();   // I can locate the froward declaration of friend function here and write fn definition inside class.

class Data {
private:
    friend class Temp;          // Friend Class: Temp Class can access Data Class Private Members Normally.
    friend void function();     // Friend Function: this is Considered the Forward Declaration
    friend std::ostream &operator<<(std::ostream &os, const Data &data) {   // Friend Operator Overloading
        os << data.privData1 << " - " << data.privData2;
        return os;
    }
    int privData1;
    int privData2;

public:
    int pubData1;
    int pubData2;
    Data(int num1, int num2) : privData1(num1), privData2(num2) {}
    void print(void);
};
void Data::print(void) {        
    std::cout << " - pubData1: " << pubData1 << std::endl;
    std::cout << " - pubData2: " << pubData2 << std::endl;
};
/********************************************************/
/********************************************************/
class Temp {
private:

public:
    Temp() {
        Data tempData1(123, 124);        // Create Instance from Data Class.
        std::cout<< "privData1: " << tempData1.privData1 << std::endl;   // Accessing the Private Memebers.
        std::cout<< "privData2: " << tempData1.privData2 << std::endl;   // Accessing the Private Memebers.
    }
};
/********************************************************/


void function(void) {
    Data tempData2(567, 568);        // Create Instance from Data Class.
    std::cout<< "privData1: " << tempData2.privData1 << std::endl;   // Accessing the Private Memebers.
    std::cout<< "privData2: " << tempData2.privData2 << std::endl;   // Accessing the Private Memebers.
}

int main() {
    Data data(500,1000);                // Aggregation Constructor/Initailization "NOT A Good Practice"
    data.print();

    Temp temp;

    function();

    return 0;
}