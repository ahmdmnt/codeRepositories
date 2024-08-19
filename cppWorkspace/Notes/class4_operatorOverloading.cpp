#include <iostream>
#include <bits/stdc++.h>
#include <ostream>

/*
Operator Overloading
*/

/********************************************************/
class Data {
    std::string message;

public:
    int dataCursor = 0;
    
    // Constructor
    Data(std::string msg, int cr) : message(msg), dataCursor(cr) {}

    // Friend Function using Class Private Memebers
    friend std::string operator+(const Data& dInstance, const std::string& msg);
    friend std::ostream& operator<<(std::ostream& os, const Data& data);

    // Class Methods
    void display () {
        std::cout<< message << std::endl;
    }

    // Operator Overloading
    Data& operator+=(const std::string& msg) {
        this->message += msg;

        return *this;   //dataInstance
    }

    bool operator<(const Data& dInstance) {
        return this->message < dInstance.message;
    }

    int operator++() {     // Pre-increment Operator Overloading
        this->dataCursor++;
        return this->dataCursor;
    }
    
    int operator++(int) {     // Post-increment Operator Overloading
        int temp = dataCursor;
        this->dataCursor++;
        return temp;
    }
};

// Operator Overloading
std::string operator+(const Data& dInstance, const std::string& msg) {
    return dInstance.message + msg;
}

std::ostream& operator<<(std::ostream& l_cout, const Data& data) {
    return l_cout << "Message: " << data.message << " - Cursor: " << data.dataCursor;
}
/********************************************************/

int main() {
    
    Data dataInstance{"Hello World!", 0};

    dataInstance.display();

    std::string extraMessage = " This is C++.";
    
    dataInstance += extraMessage;       // Operator Overloading
    dataInstance.display();

    /*
        THESE ARE NOT THE SAME
        string = Data + string      Data.operator+(string)
        string = string + Data      operator+(string, Data)
    */



    std::string newMessage = dataInstance + extraMessage;
    std::cout<< newMessage << std::endl;


    Data dataInstance1{"ABC", 0};
    Data dataInstance2{"ABCD", 0};
    if( dataInstance1 < dataInstance2 ) {
        std::cout<< "dataInstance1 < dataInstance2" << std::endl;
    }
    else { 
        std::cout<< "dataInstance1 > dataInstance2" << std::endl;
    }

    int value {0};
    ++dataInstance;
    value = ++dataInstance;         // Pre-increment Operator Overloading
    std::cout<< "dataCursor = " << dataInstance.dataCursor << "  - value = " << value << std::endl;

    value = dataInstance++;         // Post-increment Operator Overloading
    std::cout<< "dataCursor = " << dataInstance.dataCursor << "  - value = " << value << std::endl;


    /*
        cout is the calling so operator overloading function will be outside the class,
        and i need to return ostream becuz i still have code in the line " <<std::endl " ;

        std::ostream& operator<<(std::ostream& l_cout, Data& data ) { <CODE> }
    */
    std::cout<< dataInstance << std::endl;      // << Operator Overloading
    return 0;
}