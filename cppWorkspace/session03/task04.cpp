/*
* Task 04:
* 	using Class
*		Write string class which has Members {length - string}
*/

#include <iostream>
#include "myString.hpp"

int main() {
    
    myString myStringInstance{"Hello World!"};

    myStringInstance.display();

    std::string extraMessage = " This is C++.";
    
    myStringInstance += extraMessage;       // Operator Overloading
    myStringInstance.display();

    std::string newMessage = myStringInstance + extraMessage;
    std::cout<< newMessage << std::endl;


    myString myStringInstance1{"ABC"};
    myString myStringInstance2{"ABCD"};
    if( myStringInstance1 < myStringInstance2 ) {
        std::cout<< "myStringInstance1 < myStringInstance2" << std::endl;
    }
    else {
        std::cout<< "myStringInstance1 > myStringInstance2" << std::endl;
    }

    return 0;
}