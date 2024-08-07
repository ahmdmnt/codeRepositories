#include <iostream>

/*
Struct
    - By default: public scope i can add some data as private scope,
        class is private by default.
*/

struct EmployeeData {
private:
    int id;
    std::string name;

public:
    EmployeeData() {                        // Object Constructor, called automatically at object declaration
        id = 1;
        name= "default";
    };
    ~EmployeeData() {                        // Object Destructor, called automatically at object lifetime end in certain scope
        id = 0;
        name= "";
    };

    void setter(int Id, std::string N) {    // Object Methods
        id = Id;
        name= N;
    };
    void print(void) {
        std::cout << "ID: " << id << " - Name: " << name << std::endl;
    };
};



int main() {
    EmployeeData Emp1;
    Emp1.setter(100, "Ahmed");

    // std::cout << "ID: " << Emp1.id << " - Name: " << Emp1.name << std::endl;     // Error becuz in Private Scope
    Emp1.print();

    EmployeeData Emp2;
    Emp2.print();

    return 0;
}