#include <iostream>

/*
Class
    - By default: private scope i can add some data as public scope,
*/

/********************************************************/
class EmployeeData {
private:
    int id;
    std::string name;
    bool availablity;

public:
    // Object Constructor, called automatically at object declaration
    EmployeeData() {}                                       // Default Constructor
    EmployeeData(int Id) {                                  //  Parameterized Constructor
        this->id = Id;
    };
    EmployeeData(int Id, std::string Name) {                // Multiple Parameterized Constructor
        this->id = Id;
        this->name= Name;
    }
    EmployeeData(int Id, std::string Name, bool Avail) : EmployeeData(Id, Name) {   // Delegation Constructor
        this->availablity = Avail;
    };
    ~EmployeeData() {                                   // Object Destructor, called automatically at object lifetime end in certain scope
        id = 0;
        name= "";
    };

    void setter(int Id, std::string N) {    // INLINE MEMBER FUNCTION, If not used it will NOT be available in .text -- better memory util
        this->id = Id;
        name= N;
    };
    
    void print(void);                       // Definition outside class 
};
void EmployeeData::print(void) {        // If not used it will be available in .text        // BEST PRACTICE if i need to be available 
    std::cout << "ID: " << id << " - Name: " << name << " - Avail: " << availablity << std::endl;
};
/********************************************************/

/********************************************************/
class Data {
public:
    int pubData1;
    int pubData2;

    void print(void);                       // Definition outside class 
};
void Data::print(void) {        
    std::cout << " - pubData1: " << pubData1 << std::endl;
    std::cout << " - pubData2: " << pubData2 << std::endl;
};
/********************************************************/

int main() {
    EmployeeData Emp1;                                  // Default Constructor
    Emp1.setter(100, "Ahmed");          

    // std::cout << "ID: " << Emp1.id << " - Name: " << Emp1.name << std::endl;     // Error becuz in Private Scope
    Emp1.print();

    EmployeeData Emp2(120, "Huda");                     // Parameterized Constructor
    Emp2.print();

    EmployeeData Emp3(123,"Ammar", 1);                 // Delegation Constructor
    Emp3.print();

    Data data{500,1000};                // Aggregation Constructor/Initailization "NOT A Good Practice"
    data.print();

    return 0;
}