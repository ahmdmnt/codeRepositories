#include <cstddef>
#include <iostream>
#include <ostream>

/*
    User defined Literal
*/

/********************************************************/
class Data {
    std::string privString;
    int privData;

public:
    Data( std::string privString, int privData) : privString(privString), privData(privData) {}
    void print(void);
};

void Data::print(void) {        
    std::cout << " - privString: " << privString << std::endl;
    std::cout << " - privData: " << privData << std::endl << std::endl;
};

// User defined Literal for Data Class
Data operator""_dt(unsigned long long int value) {
    return Data("Default", value);
}

// Custom User defined Literal for printing String
void operator""_print(const char* myString, size_t mySize) {
    std::cout << myString << std::endl;
}
/********************************************************/

int main() {


    Data data1 {"Hello",1000}; 
    data1.print();

    Data data2 = 500_dt;        // _dt User defined Literal for Data Class
    data2.print();

    "This is My String, Followed by Print literal"_print;

    return 0;
}