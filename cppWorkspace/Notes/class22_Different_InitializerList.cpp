#include <iostream>

/*
Initializer List Difference:

    Type of Constructors:
    - Aggregate Constructor:
    when there is no constructor ... it will be used ... 
        Syntax -->>  myData data1 {1, 2};
    - Initializer List Constrcutor:

*/

/********************************************************/
class myData {
public:
    int varData1;
    int varData2;
};

class Data {
public:
    int varData1;
    int varData2;

    Data(int v1, int v2) : varData1(v1), varData2(v2) {
        std::cout<< "Constructor" << std::endl;
    }

    Data(std::initializer_list<int> v) {
        std::cout<< "Constructor, using Initializer List" << std::endl;
    }
};
/****************************************************************************/  

int main() {

    myData d1{1, 2};        // will use Aggregate Constructor

    Data d2{1, 2};          // will use Constructor, using Initializer List
    Data d3(1, 2);          // will use Constructor

    return 0;
}
