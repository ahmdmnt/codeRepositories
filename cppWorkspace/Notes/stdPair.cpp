#include <iostream>
#include <tuple>
#include <vector>

/*
    std::pair()
    Creating pair of Datatypes
*/

int main() {

    std::pair<int, std::string> pairVariable {10001, "Ahmed Montasser"};

    /* Accessing Pairs */
    std::cout<< "First in Pair: " << pairVariable.first << std::endl;
    std::cout<< "Second in Pair: " << pairVariable.second << std::endl;

    /* Re-Assinging Pairs */
    pairVariable.first = 10008;
    pairVariable.second = "Mohamed Ahmed";
    std::cout<< "First in Pair: " << pairVariable.first << std::endl;
    std::cout<< "Second in Pair: " << pairVariable.second << std::endl;

    return 0;
}
