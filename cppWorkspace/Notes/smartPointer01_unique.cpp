/*
    Smart Pointer: 
        Normally it construct the Pointer for you and Initialize it with value if passed.
        and in code end the destructor delete and free the pointer to avoid Memory Leakage.
*/
#include <iostream>
#include <memory>
#include <cstdio>

class myPointer {
    int* ptrVariable = new int();
    myPointer(int* ptr = nullptr) : ptrVariable(ptr) {
        std::cout << "myPointer Constructor" << std::endl;
    }
    ~myPointer() {
        std::cout << "myPointer Destructor" << std::endl;
        if(ptrVariable) {
            delete ptrVariable;
            ptrVariable = nullptr;
        }
    }
};

void function1(const std::unique_ptr<int>& l_ptr) {     // BEST PRACTICE
    std::cout<< "function2: " << *l_ptr << std::endl;
}
void function2(std::unique_ptr<int> l_ptr) {
    std::cout<< "function1: " << *l_ptr << std::endl;
}


/*
    Deletor Class for pointer to file
*/
class fileDeletor {
public:
    void operator()(FILE *file) const {
        if(file) {
            std::cout<< "Closing file" << std::endl;
            fclose(file);
        }
    }
};

int main() {
    /*
        Unique Pointer is ownership of Smart Pointer.
        > No multiple assignation of Pointers.
            - No Copy Constructor.
            - No Assignment Operator.
            - Move working Normally.
            - Can't Copy in Function Argument... either Move or call a const Reference (IMPORTANT)
    */
    std::unique_ptr<int> ptr = std::make_unique<int>(150);
    // std::unique_ptr<int> ptr1 = ptr;    // Assignment and Copy is deleted in Unique Pointers
    // std::unique_ptr<int> ptr2 = std::copy(ptr);    // Assignment and Copy is deleted in Unique Pointers
    std::unique_ptr<int> ptr3 = std::move(ptr);

    function1(ptr3);
    function2(std::move(ptr3));

    std::unique_ptr<int> ptr4 = std::make_unique<int>(110);
    std::cout<< "Raw Pointer: " << ptr4.get() << std::endl;

    std::unique_ptr<int> ptr5 = std::make_unique<int>(20);
    // ptr4.swap(std::unique_ptr<int>& ptr5);
    std::cout<< "ptr4: " << *ptr4 << std::endl;
    std::cout<< "ptr5: " << *ptr5 << std::endl;
    ptr4.release();     // Deleting Manually  (Call Destructor)

    /*
        I Can change the deletion handling of Unique Pointer.
        - Default : Default Deletion.
        - User-Defined Deletion function.
    */
    auto uniquePtrDeletion = [](int* l_ptr) {
        std::cout<< "Unique Pointer User-Defined Deletion Function" << std::endl;
        delete l_ptr;
    };

    std::unique_ptr<int, decltype(uniquePtrDeletion)> ptr6(new int(33), uniquePtrDeletion);
    std::cout<< "ptr6: " << *ptr6 << std::endl;


    /*
    ADVANCED EXAMPLE:
        Good Practice for Uniquie Pointer ... Pointer to File with Deletion Function to close file
    */
    std::unique_ptr<FILE, fileDeletor> file(fopen("example.txt", "w"));       // fileDeletor is already a class==Datatype so no need to decltype()
    if(file) {
        std::cout<< "File Opened" << std::endl;
        fprintf(file.get(), "Hello World!");
    }
    else {
        std::cout << "Failed to open file" << std::endl;
    }

    return 0;
}