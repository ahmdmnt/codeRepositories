/*
    Smart Pointer: 
        Normally it construct the Pointer for you and Initialize it with value if passed.
        and in code end the destructor delete and free the pointer to avoid Memory Leakage.
*/
#include <iostream>
#include <memory>
#include <cstdio>
 

int main() {
    /*
        Shared Pointer is same as unique pointer ... but multiple pointer can point to same Data.
        > Multiple assignation of Pointers.
            - Copy Constructor.
            - Assignment Operator.
            - Move Constructor.
            - it contain [Counter] knows the count of pointers that are pointing to same Data. (IMPORTANT)
    */

    std::shared_ptr<int> ptr1 = std::make_shared<int>(10);
    *ptr1 = 100;
    std::shared_ptr<int> ptr2 = ptr1;
    std::shared_ptr<int> ptr3 = ptr2;
    std::cout<< "Pointer Count: " << ptr1.use_count() << "-" << ptr2.use_count() << std::endl;
    std::cout<< "Pointer Value: " << *ptr1 << "-" << *ptr2 << "-" << *ptr3 << std::endl;
    /*
        Deletion will occur when all pointers are deleted
    */
    ptr3.reset();
    ptr1.reset();
    ptr2.reset();
    std::cout<< "Pointer Count: " << ptr1.use_count() << std::endl;

    /*
        Can switch to unique pointer
    */
    std::shared_ptr<int> ptr4 = std::make_shared<int>(20);
    ptr4.unique();
    // std::shared_ptr<int> ptr5 = ptr4;

    return 0;
}