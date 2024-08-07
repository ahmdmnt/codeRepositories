#include <iostream>

/*
Class
    - Initializer List:
        Mandotory when intializing :
            1. Reference Variable.
            2. const Variable.
            3. ?? Inherietance

    - Delete Keyword
        1. Delete default construtor.
        2. Delete some inhereited functions/members?? from the other class.

    - const member
        1. can be init directly.
        2. can be init in initailizer list

    - const method
        1. cannot modify any member within const method.
        2. can modify MUTABLE members only within const method.
        3. create and modify any local variable in const method.
        4. create and modify any fn args  variable in cont method.
        5. create and modify any static members in const method.
        6. modify any reference members in const method.
        7. can NOT modify the pointer address itself member in const method but i can modify the pointing value.
        8. const object instance -- can only call const members function.   
            EmployeeData Emp1;       -> can call both const and normal fns.
                                     -> call non const function if two fn const and non-const available.
            const EmployeeData Emp1; -> can call const fns only.

*/

/********************************************************/
class EmployeeData {
private:
    int& id;
    std::string name;
    bool availablity;
    const int data1;        // Initializer List
    const int data2=0;      // Direct Init
    int data = 2000;        // add mutable int data >> to modify member in constant method
    int* ptrData = &data;
    int& refData = data;
    static int statData;

public:
    // Initailizer List in Object Constructor
    EmployeeData() = delete;                // IMPORTANT: Delete ability of using default constructor
    EmployeeData(int ID, int d) : id(ID), data1(d){}        // IMPORTANT: Initializer List is Mandatory when defining reference variable
    EmployeeData(int ID, std::string NAME, int d) : id(ID), name(NAME), data1(d){}
    EmployeeData(int ID, std::string NAME, bool AVAIL, int d) : id(ID), name(NAME), availablity(AVAIL), data1(d){}

    void print(void) const;

    //int* get_ptrData() {      // MISRA ISSUE: Cannot return Pointer of Private Member, "gives the ablity to edit it outside class"
    const int* get_ptrData() {  // BEST PRACTICE 
        return ptrData;
    };
    // int& get_refData() {     // MISRA ISSUE: Cannot return reference of Private Member, "gives the ablity to edit it outside class"
    const int& get_refData() {  // BEST PRACTICE 
        return refData;
    };
};
void EmployeeData::print(void) const {
    /*
    Const Method
    */
    // refData = 10000;     OK TO MODIFY
    // ptrData = &data;     FORBIDDEN
    // *ptrData = 10000;    OK TO MODIFY   
    // statData++;       // OK TO MODIFY in const method //// ISSUE IN THIS LINE ////
    std::cout << "ID: " << id << " - Name: " << name << " - Avail: " << availablity << std::endl;
    std::cout << "StaticData: " << statData << std::endl;
    std::cout << "data: " << data << std::endl;
};
/********************************************************/


int main() {
    // EmployeeData Emp1;      //Error becuz default constructor is deleted

    int id1= 100;
    EmployeeData Emp1(id1, 1);
    Emp1.print();          

    int id2= 150;
    EmployeeData Emp2(id2, "Ahmed", 1);
    Emp2.print(); 

    int id3= 200;
    EmployeeData Emp3(id3, "Mohamed", 1, 1);
    const int* ptr1 = Emp3.get_ptrData();
    // *ptr1 = 300;    // FORBIDDEN:: BECUZ PTR on a const value
    const int& ref1 = Emp3.get_refData();
    // ref1 = 300;    // FORBIDDEN:: BECUZ Ref on a const value
    Emp3.print();

    return 0;
} 