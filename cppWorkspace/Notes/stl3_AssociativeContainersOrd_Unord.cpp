#include <iostream>
#include <set>
#include <unordered_set>

/*
    SET/UNODERED_SET:
        Syntax: 
            std::set   -    std::unorderedset
        
        Same as Python set ... Ordered/Unordered Unqiue list

*/
/*
    MULTISET/UNODERED_MULTISET:
        Syntax: 
            std::multiset   -    std::multiunorderedset

*/

void print(std::set<int>& l_set);
void print(std::unordered_set<int>& l_set);
void print(std::multiset<int>& l_set);
void print(std::unordered_multiset<int>& l_set);

int main() {

    /*
        SET
    */
    std::set<int> ordSetVar {1, 30, 20, 5, 10, 10, 10};
    print(ordSetVar);

    ordSetVar.insert(2);
    ordSetVar.erase(5);
    print(ordSetVar);

    /* NO SEQUENCE --> NO INDEXING --> Locating by find only */
    // ordSetVar[1] = 10;
    auto it = ordSetVar.find(25);
    std::cout<< std::boolalpha << (it==ordSetVar.end()) << " - " << *it << std::endl;

    it = ordSetVar.find(30);
    std::cout<< std::boolalpha << (it==ordSetVar.end()) << " - " << *it << std::endl;


    /*
        UNORDERED_SET
    */
    std::unordered_set<int> unordSetVar {1, 30, 20, 5, 10, 10, 10};
    print(unordSetVar);


    /*
        MULTI SET / UNORDERED MULTISET..... 
        not unique members can hold multiple instance of value
    */
    std::multiset<int> ordMuSetVar {1, 30, 20, 5, 10, 10, 10};
    print(ordMuSetVar);

    std::unordered_multiset<int> unordMuSetVar {1, 30, 20, 5, 10, 10, 10};
    print(unordMuSetVar);

    return 0;
}

void print(std::set<int>& l_set) {
    for(int ele: l_set) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;
}

void print(std::unordered_set<int>& l_set) {
    for(int ele: l_set) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;
}

void print(std::multiset<int>& l_set) {
    for(int ele: l_set) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;
}

void print(std::unordered_multiset<int>& l_set) {
    for(int ele: l_set) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;
}