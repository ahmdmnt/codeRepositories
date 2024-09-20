#include <iostream>
#include <memory>
#include <cstdio>

/*
    Template Class - Constant Expression
*/
template<typename T, int size> class myContaniner {
public:
    T arrVariable[size];
    
    myContaniner(const T* l_vec) {
        for(int it=0; it<size; it++) {
            *(arrVariable+it) = *(l_vec+it); 
        }
    }
    void print() {
        for(int it=0; it<size; it++) {
            std::cout<< arrVariable[it] << "-"; 
        }
        std::cout<< std::endl;
    }
};


int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    /*
        myConatiner except const experession
        myContaniner<DATATYPE, CONSTANT_VALUE>
    */
    myContaniner<int, 5> containerInstance1(arr);   // 2nd Argument datatype is not entered, so it will consider it as default = int (Casting occured)
    containerInstance1.print();

    return 0;
}
