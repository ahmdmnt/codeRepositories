#include <iostream>
#include <ostream>
#include <utility>

/*
    Value Category
        - Lvalue    : Lvalue = has Name + has Address + Not Movable
        ------------------------------------------------------------
            > Named by Programmer.
            > Lvalue is initialized by Lvalue/Rvalue.
            > has its ownership. """"

        - Xvalue    : Xvalue = has Name + has Address + Moved
        -------------------------------------------------------
            > Has identity and movable

        - Rvalue    : Rvalue = No Name + Temporary
        --------------------------------------------
            > Programmer never have the chance to name Rvalue.
            > no initialized, it is the value by itself.
            > values, 3,4,5.5,'a',true, literals etc...

    Type Category
        - Lvalue Reference  
        ------------------------------------------------------------
            > Alias to Lvalue.
            > must be initialized with Lvalue not Rvalue.

        - Rvalue Reference 
        --------------------------------------------
            > Alias to Rvalue (Movement to a location "Movement Semantic").
            >  has Sole Ownership ... can't be shared with another lValue ... 

    NOTE:
        1. We Can Consider:
            Const Lvalue Reference => Reference to Rvalue.
            Const Lvalue Reference => Reference to Temporary Lvalue.
            { - Const Type& is Special case - }

    Summary
    lv accepts   > rv, lv and lvr
    lvr accepts  > lv, and lvr
    clvr accepts > rv, lv and lvr
*/
/********************************************************/

///////////////////////////////////////////////////////////////////
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
        this->privData = tmp.privData;      // MEMORY LEAKAGE
    };
    Data(Data&& tmp) {
        std::cout<< "Move Constructor" << std::endl;
        /*
        1- Move Trivial Data type from tmp to this Instance.
        2- Reset any non-trivial data type after movement.
        */
        this->privData = tmp.privData;
        tmp.privData = nullptr;
    };

    /**
     * @brief COPY Assignment
     *      Without Below API ... this Error Pops up .. Memory leakage issue.
     *      free(): double free detected in tcache 2
     *      Aborted (core dumped)
    */
    Data& operator=(const Data& instance) {
        std::cout<< "Copy Assignment Operation" << std::endl;
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

        /**
     * @brief MOVE Assignment
     *      Without Below API ... this Error Pops up .. Memory leakage issue.
     *      free(): double free detected in tcache 2
     *      Aborted (core dumped)
    */
    Data& operator=(Data&& instance) {
        std::cout<< "Move Assignment Operation" << std::endl;
        /* Self-Assignment Handling .. otherwise i will move myself and i already deleted me*/
        if(this == &instance)
            return *this;

        if( this->privData!= nullptr ) {                        // Solution2: Clean before new assigning Address (RECOMMENDED).
        delete privData;
        privData = nullptr;  
        this->privData = new int(*(instance.privData));         // Self Assignment should be handled.

        delete instance.privData;                               // Delete instance after moving
        instance.privData = nullptr;
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
///////////////////////////////////////////////////////////////////////////

void function(int x) {};
void function2(int& x) {};
void function3(const int& x) {};


int main() {
    int var1 {10};              // Lvalue
    int& varRef {var1};         // Lvalue / LvalueRef

    function(1);             // 1 is RValue and X is Lvalue
    function(var1);          // var1 in expression is RValue and X is Lvalue
    function(varRef);        // [IMP],, bcuz Ref is also Lvalue .... so it can be in this expression a RValue

    function2(var1);        // becuz var1 is Lvalue .. it is OK
    function2(varRef);      // becuz varRef is Lvalue .. it is OK
    // function2(1);           // becuz "1" is NOT Lvalue .. ERROR 

    function3(1);            // [const type&] this will pass .. becuz 1 is now in Temp and x in function3 is reference to Temp

    std::cout<< "var1 = " << var1 << std::endl;
    std::cout<< "varRef = " << varRef << std::endl;

    std::string name1 {"Ahmed"};
    // Name 2 take the ownership from name1 and name1 is empty now..
    std::string name2 {std::move(name1)};       // Move Constructor
    // Name 3 replaces with name1 ... but data are in the same location
    std::string&& name3 {std::move(name1)};     // Alias no Movings


    // IMPORTANTTTTTT
    Data myData1 {1};
    
    Data&& myData2 {std::move(myData1)};    // No moving adding just alias Alias
    myData1.print();
    myData2.print();

    Data myData3 {std::move(myData1)};      // Move happens --  if no Move, use Copy -- if no copy, Error 
    // myData1.print();                     // Runtime Error,, becuz MyData1 is moved to myData3
    myData3.print();

    Data myData4 {10};
    Data myData5 {10};
    myData5 = myData4;                  // Copy Assignment both 4 and 5 are available
    myData4.print();
    myData5.print();
    
    myData5 = std::move(myData4);       // 4 is no longer available
    myData5.print();
    // myData4.print();                 // Runtime Error,, becuz MyData1 is moved to myData3

    myData5 = std::move(myData5);       // Hanlding moving myself 
    myData5.print();

    return 0;
}