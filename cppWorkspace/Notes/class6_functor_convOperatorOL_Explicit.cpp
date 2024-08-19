#include <iostream>
#include <bits/stdc++.h>
#include <ostream>
#include <string>

/*
    Functor
*/

/********************************************************/
class Data {
    std::string message;
    int dataCursor = 0;

public:

    Data(std::string msg) : message(msg) {}
    // explicit Data(std::string msg) : message(msg) {}         MISRA: If i have constuctor with one arg i should add explicit to avoid implicit casting.

    Data(std::string msg, int cr) : message(msg), dataCursor(cr) { std::cout<< "Constructor Called." << std::endl; }
    friend std::ostream& operator<<(std::ostream& os, const Data& data);

    // FUNCTOR
    void operator() (void) {            // either to leave empty or add void in args it wont matter void operator() ()/void operator() (void)
        std::cout << "******************" << std::endl;
        std::cout << "Hello this is a FUNCTOR.." << std::endl;
        std::cout << *this << std::endl;
        std::cout << "******************" << std::endl;
    }

    // Conversion Operator Overloading
    operator std::string() {
        return message;
    }
};

std::ostream& operator<<(std::ostream& l_cout, const Data& data) {
    return l_cout << "Message: " << data.message << " - Cursor: " << data.dataCursor;
}
/********************************************************/

int main() {
    
    Data dataInstance{"Hello World!", 0};
    std::cout<< dataInstance << std::endl;

    dataInstance();             // Functor Call
    
    Data("ABCD", 10);    // This is a TEMP ... Created and Destroyed in same line.
    Data("WXYZ", 20)();  // Functor Call also, from temp object

    /*
    1. Create a TEMP Object 
    2. Move it to an Object instance in std::function Class
    */
    std::function<void(void)> f = Data("EFG", 5);
    f();                        // Functor Call,, once call f(); ... it will call the functor

    // Conversion Operator Overloading (Implicit Conv)
    std::string newMessage = dataInstance;      // Conversion Operator Overloading. .. converting Data class object to std::string variable value.
    std::cout<< newMessage << std::endl;

    /*
    to Avoid it add explicit in constructor definition
    */
    Data data22 = std::string("Implicit Casting Occured >> Data (std::string(<VALUE>) ");

    /*
    GOOD PRACTICE IN CONVERSION (Explicit Conv)
    */
    std::string newMessage22 = static_cast<std::string>(dataInstance);
    Data data33 = static_cast<Data>(std::string("Data33"));

    

    return 0;
}