#include <iostream>
#include <vector>

enum Traffic1 {
    RED,        // 0 
    YELLOW,     // 1
    GREEN       // 2
};

enum class Traffic2 : unsigned char {
    RED,        // 0 
    YELLOW,     // 1
    GREEN       // 2
};

int main() {

    /*
    C-Style Enum
        Issues:
            1. Convert ENUM values as normal integer.
            2. Fixed size = to 4B.
            3. Redefine of Enum values cannot be done.
        Good Point:
        Detect if assigning Integer values ... will ask for casting
    */
    Traffic1 traffic_1 = GREEN;
    std::cout<< traffic_1 << std::endl;

    int number = YELLOW;    // Issue 1.

    traffic_1 = static_cast<Traffic1>(5);
    std::cout<< traffic_1 << std::endl; 

    /*
    Enum Class
            1. Can not Convert ENUM values as normal integer.
            2. Not Fixed size = to 4B.
            3. ability to redefine.
            4. Scope Resolution.
        Detect if assigning Integer values ... will ask for casting
    */
    Traffic2 traffic_2 {};
    std::cout<< Traffic2::RED << std::endl;
    // std::cout<< traffic_2 << std::endl;      // Error should define operator overloading method
    // int number1 = static_cast<int>(Traffic2::RED);             // Error should define operator overloading method

    return 0;
}