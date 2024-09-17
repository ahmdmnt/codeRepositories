/*
    Dynamic Memory Allocation: new / delete keywords
*/
#include <iostream>


int main() {

    // Heap and Dynamic Memory allocation
    int *intPtr = new int(10);      // Allocate and Initalize
    std::cout << "intPtr: " << *intPtr << std::endl;     

    *intPtr = 45;                   // Set Data
    delete intPtr;                  // Delete allocated value
    intPtr = nullptr;               // IMPORTANT: Remove pointing address


    /*
        IMPORTANT NOTE:
        by default: if new available space in Heap ...
        it will throw error,,,
    */
    int *ptrVariable1 = new int();
    *ptrVariable1 = 100;
    std::cout << "ptrVariable1= " << *ptrVariable1 << std::endl;

    /*
        You can disable the throw,
        and if no available space it will return nullptr... 
        u have to check if variable is allocated or not
    */
    int *ptrVariable2 = new (std::nothrow) int();
    if(ptrVariable2 == nullptr) {
        std::cout<< "LOG::ERROR:: Memory Allocation Failed for ptrVariable2 variable!" << std::endl;
    }
    else {
        *ptrVariable2 = 255;
        std::cout << "ptrVariable2= " << *ptrVariable2 << std::endl;
    }

    /*
        After using dynamic memory allocation variable..
        you should delete them
    */
    delete ptrVariable1;
    ptrVariable1 = nullptr;
    delete ptrVariable2;
    ptrVariable2 = nullptr;

    /* CAN'T USE IT AFTER DELEATION */


    return 0;
}
 