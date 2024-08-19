#include <algorithm>
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
*/

/********************************************************/
int& function() {
    static int num = 10;
    return num;
}
/********************************************************/

int main() {
    int x /*Lvalue*/= 0 /*Rvalue*/;

    (x /*Lvalue*/=5 /*Rvalue*/) /*Lvalue*/ =  6 /*Lvalue*/;
    std::cout<< "x= " << x << std::endl;

    // (x+1) /*Rvalue*/ = 10 /*Lvalue*/;
    // &x /*Rvalue*/ = 10 /*Rvalue*/;

    function() /*Lvalue*/ = 50;     //
    std::cout<< "function()= " << function() << std::endl;

    int y = function();             // will be rValue
    std::cout<< "y= " << y << std::endl;




    int num1 = 10;          //Lvalue
    int& numAlias = num1;   //LvalueRef ... init with Lvalue not Rvalue.

    int&& numRValueRef = std::move(num1);    // Value Cat.: Lvalue - Type Cat. : RvalueRef
    // Num1 is no longer there... ownership moved to numRValueRef ... FOR (NON TRIVIAL DATATYPES) !!!!!

    std::string name1 = "Ahmed";                // Name1 is an lvalue
    std::string&& name2 = std::move(name1);     // Name2 is an lvalue, but now Name1 is an Xvalue: has identituy and moved.

    std::cout << "name1: " << name1 << std::endl;
    std::cout << "name2: " << name2 << std::endl;

    return 0;
}