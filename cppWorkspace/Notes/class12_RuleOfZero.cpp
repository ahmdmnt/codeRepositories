#include <iostream>

/*
Rule of Zero:
    - Make all Construnctors Default, doesn't Implement any Copy/Move etc.. API.
    - If used in Polymorphism,, i have to type all consts and destructor prototypes and equalize it with default.
*/

/********************************************************/
class Data {
public:
    std::string myString;
    int pu_Data1;

    /**
    * > Rule of Zero ... (5 Defaults)
    *   - Set all Constructors and Destructor to default.
    *   - Below Prototypes are created by default, it is only mandatory in Polymorphism.
    *   - If i want to disable all features regarding Copy/Move ... Put "delete" instead of Default
    *   - if Pointers used, Implement Copy/Move Constructor/Assignment becuz default will make shallow copy .. and use only default Destructor.
    */
    Data(const Data& instance) = default;                   // 1. Copy Constructor -> Default
    Data(Data&& instance) = default;                        // 2. Move Constructor -> Default
    Data& operator=(const Data& instance) = default;        // 3. Copy Assignment Operator -> Default
    Data& operator=(Data&& instance) = default;             // 4. Move Assignment Operator -> Default
    virtual ~Data() = default;                              // 5. Destructor -> Default     "virtual will be discussed later in Poly."
    /*************************************************************************************************/
    
    /* Initialization Constructor is not related to Rule of Zero, can be Normally Implemented. */
    Data(std::string l_string, int data) : myString(l_string), pu_Data1(data) {}      // Just added this Constructor

    void print(void) {        
    std::cout << " - pu_Data1: " << pu_Data1 << std::endl;
    std::cout << " - myString: " << myString << std::endl;
    };
};

/********************************************************/

int main() {

    Data data1("Ahmed", 10);

    Data data2(data1);              // 1. Copy Constructor   
    Data data3(std::move(data1));   // 2. Move Constructor
    data2 = data3;                  // 3. Copy Assignment Operator
    data3 = std::move(data2);       // 4. Move Assignment Operator

    data1.print();
    data2.print();
    data3.print();

    return 0;
}
