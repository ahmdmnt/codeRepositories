/*
    Algorithm and RAII: Resource Aquistion Initialization

    Libraries:
        1. Algorithm
        2. Numeric

    Basic template for functions/methods in Algorithm
        (beginPtr, endPtr, value/ptr/iterator/function)
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>

/*
    Defined in Std::Exception
*/
class myCustomException: public std::exception {
public:
    const char* what() const noexcept override {
        return "myCustomException Description";
    }
};

/*
    noexcept
    - noexcept(true/false) -->> disable throwing exceptions.
    - noexcept(expression) -->>
*/

void fun3() {
    throw "funtion3 exception";
}
void fun2() {
    try {
        fun3();
    }
    catch (...){
        throw;  // this only re-throw for exception in function 3 ... [Not Mandatory]
    }
}
void fun1() {
    try {
        fun2();
    }
    catch (...){
        throw;  // this only re-throw for exception in function 3 ... [Not Mandatory]
    }
}

int main() try {

    fun1();

    try {
        throw "User-defined Error";                         // throw user-defined error
        throw std::runtime_error("Error Description");      // STD Error
        throw 5;                                            // Undefied error
    }
    catch (const char* err) {                    // Catch User-defined Errors
        std::cout<< "[1] Exception caught:: " << err << std::endl;
    }
    catch (std::exception& err) {          // catch STD Errors
        std::cout<< "[2] Exception caught:: " << err.what() << std::endl;
    }
    catch (myCustomException& err) {       // Custom STD Errors
        std::cout<< "[2] Exception caught:: " << err.what() << std::endl;
    }
    catch (...) {                                // Catch else Errors .. usually done when no catching user-defined errors "not commonly used"
        std::cout<< "[3] Exception caught:: Unknown Exception" << std::endl;
    }

    return 0;
}
catch (const char* err) {
    std::cout<< "[3] Exception caught:: " << err << std::endl;
}