#include <iostream>
#include <vector>



int main() {
    /*
    Different types of Initialization
        Best Practice > Uniform initialzation
            do extra compilation check
    */
    int num1 = 10;  // Copy Initialization
    int num2 (20);  // Direct Initialization
    int num3 {30};  // Value/Uniform Initialization
    std::cout<< num1 << "-" << num2 << "-" << num3 << std::endl;

    int val_1;        // Garbage value
    int val_2 {};     // Init = 0
    //int val_3 ();   // Vexing Parse
    std::cout<< val_1 << "-" << val_2 << std::endl;


    std::vector <int> list1 (10, 3);    // Direct
    std::vector <int> list2 {10, 3};    // Uniform

    auto printVector = [](std::vector <int> list) {
        for (int i : list) {
            std::cout<< i << " ";
        }
        std::cout<< std::endl;
    };
    printVector(list1);
    printVector(list2);

    return 0;
}