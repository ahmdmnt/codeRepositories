#include <iostream>
#include <vector>

int main() {
    // 3- Vectors
    std::vector<int> numList{10, 11, 12, 13, 14, 15};

    // 4- Ranged-base for Loop
    for(auto itr: numList) {        // 5- auto ,, automatic detect datatype 
        std::cout << itr << " ";
    } 
    std::cout<< std::endl;
          // Remove pointing address

    return 0;
}