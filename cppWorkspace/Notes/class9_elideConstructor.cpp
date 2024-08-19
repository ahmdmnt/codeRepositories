#include <iostream>
#include <ostream>

/*
    Elide Constructor
    Optimization done by C++ Compiler... Omitting creating temp Instance
*/

/********************************************************/
class Data {
    int *privData;

public:
    Data(int value) {      // Default Constructor
        std::cout<< "Constructor" << std::endl;
        this->privData = new int(value);
    };
    ~Data() {              // Destructor.
        std::cout<< "Destructor" << std::endl;
        delete privData;
        privData = nullptr;  
    };
    Data(const Data& tmp) {
        std::cout<< "Copy Constructor" << std::endl;
    };
    /**
     * @brief Without Below API ... this Error Pops up .. Memory leakage issue.
     *      free(): double free detected in tcache 2
     *      Aborted (core dumped)
    */
    Data& operator=(const Data& instance) {
        std::cout<< "Assignment Operation" << std::endl;
        *(this->privData) = *(instance.privData);               // Solution1: Allocation it to same instance address
        // if for example ,,, ptr to char and size is different this will cause issue.


        /* Self-Assignment Handling*/
        if(this == &instance)
            return *this;

        if( this->privData!= nullptr ) {                        // Solution2: Clean before new assigning Address (RECOMMENDED).
        delete privData;
        privData = nullptr;  
        this->privData = new int(*(instance.privData));         // Self Assignment should be handled.
        }

        return *this;
    };
    void print(void) {        
        std::cout << " - *privData: " << *privData << std::endl << std::endl;
    };
};

Data /*temp*/ get_instance() {
    Data instance{5};      // 1. Create local Instance  "Constructor"
    return instance;    // 2. Copy it in temp instance "Copy Constructor"
    // 3. Delete Local instance
};
/********************************************************/

int main() {
    Data dataInstance1(get_instance());  // 4. Copy Constructor
    // 5. Delete Temp
    // 6. Delete dataInstance

    Data dataInstance2{20};
    dataInstance2 = dataInstance1;      // Assigning dataInstance2 with dataInstance1 no creation/constructor only OperatorOverloading

    dataInstance2.print();    
    return 0;
}

/**
 * to test the code run below command: 
 * disable any optmization
 *   > g++ class9_elideConstructor.cpp -std=c++14 -fno-elide-constructors && ./a.out
 *
 *      Constructor         1
 *      Copy Constructor    2
 *      Destructor          3
 *      Copy Constructor    4
 *      Destructor          5
 *      Destructor          6
 */