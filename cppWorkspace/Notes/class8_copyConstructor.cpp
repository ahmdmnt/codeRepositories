#include <cstddef>
#include <cstring>
#include <iostream>
#include <ostream>

/*
    Copy Constructor:
    if i send to an Class Instance another class instance.

    if not implemented, compiler will automatically create one (Implicit): 
        - set the members of new object with the sent object.
        - New one will be reference to one also,, will be affected with its changes.  IMPORTANT

---------------------------------------------------------------------------------------------------------------
        1. Why Copy Const. must pass a reference arguemnt??
            - to avoid infinite loop of recursive calling.. no exist criteria.
        2. Why Copy Const. must be constant?
            - to handle TEMP Variable in Copy Constructor ... like get_instance() api
*/

/********************************************************/
class Data {
    std::string privString;
    int privData;

public:
    Data(std::string privString, int privData) : privString(privString), privData(privData) {}

    void setData(int data) {        
        privData = data;
    }
    
    void setString(std::string str) {
        privString = str;
    }
    
     void print(void) {
        std::cout << " - privString: " << privString << std::endl;
        std::cout << " - privData: " << privData << std::endl << std::endl;
    }
};

class String {
    char* privString;
    int privSize;

public:
    // Construnctor:
    String(char* str, int size) : privString(str), privSize(size) {}

    // Copy Constructor:
    //    > Constant and Referenced Argument from same Class.
    String(const String& strInstance) {
        privSize = strInstance.privSize;

        privString = new char[privSize];            // Memory Leakage will occur should be solved.
        strcpy(privString, strInstance.privString);
    }

    void setChar(char myChar) {
        *privString = myChar;
    }
    
    void print(void) {
        std::cout << " - privString: " << privString << std::endl;
        std::cout << " - privSize: " << privSize << std::endl << std::endl;
    }
};
/********************************************************/

String get_instance() {         // Available from C++17
    static char strArray[] = "ABCD";
    
    String strTEMP{strArray, 5};        //This a TEMP Variable
    return strTEMP;
}

int main() {
    Data data1 {"Hello",1000}; 
    data1.print();

    /*
        Implicit Copy Constructor is created >>> 
        Data (Data& dInstance)
    */
    Data data2(data1);      // Copy Constructor -- if not implemented, compiler will automatically create one
    data2.print();
    
    data1.setString("Bye");
    data1.setData(123);
    data1.print();

    data2.print();


    char strArray[] = "Hello";
    String str1 (strArray, 6);
    str1.print();

    String str2(str1);                  // Becuz there is pointer or Ref ... Issue will occur

    str1.setChar('A');          // [[ISSUE]] str2 has same reference of str2 ... i have to create Copy Constructor myself
    str1.print();
    str2.print();

    String str3(get_instance()/*<-- TemperoryVariable*/);        // I removed the const from COpy Constructor and Issue not appear? 
    str3.print();

    return 0;
}