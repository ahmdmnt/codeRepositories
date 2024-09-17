/*
    Namespace: Containerization of code together.
*/
#include <iostream>

namespace myContainer_1 {       // User-defined namespace
    namespace myVector {        // Nested Namespace
        unsigned int myVariable = 0;
        void print() {
            std::cout << "myContainer_1::myVector::print()" << std::endl;
        }
    }
}

namespace myContainer_2 {
    unsigned int myVariable = 0;
}

int main() {
    myContainer_2::myVariable;    

    namespace mCV = myContainer_1::myVector;    // Alliasing Long namespace
    myContainer_1::myVector::myVariable;
    mCV::myVariable; 

    using namespace myContainer_1::myVector;        // Local using of namespace.... BAD PRACTICE
    print();

    return 0;
}
 