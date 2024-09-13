#include <iostream>
#include <vector>
#include <array>

/*
    STL: Standard Template Library
    CPP providing Standard Libraries for type Template to be used.
    it can be used with multiple basic types.
        - Contatiners.
            - Sequence Containers:                          "Ordered Listing"
                - Array:        Static Arrays.
                - String:       Sequence of characters
                - Vector:       Dynamic Arrays.
                - Deque:        Double ended Queue.
                - List:         Doubly LinkedList.
                - ForwardList:  Single LinkedList.  
            - Associative Containers:                       "Key & Value Listing"
                - Set:          Collection of unique Elements.
                - Multiset     
                - Map:          Key-Value Pairs .. Sorted by key.
                - Multimap.   
            - Unordered Associative Containers:             "Unordered Key & Value Listing"
                - Unordered Set:          Collection of unique Elements.
                - Unordered Multiset     
                - Unordered Map:          Key-Value Pairs .. Sorted by key.
                - Unordered Multimap. 
            - Container Adapters.
                - Stack:            LIFO, structure
                - Queue:            FIFO, structure
                - Priority Queue:   FIFO, structure

        - Itretors: powerful tool that allow movin in containers.
            - Input Iterator
            - Output Iterator
            - Forward Iterator
            - Bidirectional Iterator
            - Random Access Iterator
        - Algorithms: Set of Operations available in CPP .. can be used with conatiners also
            - Sorting
            - Searching
            - Manipulation
*/

/*
    Core C++ Guidelines:
    Preferred to use VECTORS, unless you have a reason to use different conatiner.
    Vector Benefits:
        - Fastest access.
        - fastest access patterns.
        - lowest overhead.
*/

/*
    ARRAYS:
        Syntax: 
            std::array
        Type:
            STL > CONTATINERS > SEQUENCE CONTAINER > ARRAY

*/
/*
    VECTORS:
        Syntax: 
            std::vector
        Type:
            STL > CONTATINERS > SEQUENCE CONTAINER > VECTOR

*/

void std_array(void);
void std_vector(void);
void printVector(std::vector<int>& l_vect);

int main() {

    std_array();
    
    std::cout<< std::endl;std::cout<< std::endl;
    
    std_vector();

    return 0;
}

void std_array(void) {
    std::array<int, 6> arrVar = {0, 10, 20, 30, 40, 50};

    std::cout<< "Array Size: " << arrVar.size() << std::endl;
    std::cout<< "Array Max Size: " << arrVar.max_size() << std::endl;

    std::cout<< "Is Array Empty: " << arrVar.empty() << std::endl;

    // Return Pointer to Elements
    std::cout<< "Array Begin Pointer: " << *(arrVar.begin()+1) << std::endl;         // arrVar.cbegin() >> return const iterator
    std::cout<< "Array End: " << *(arrVar.end()-1) << std::endl;

    std::cout<< "Array Front: " << arrVar.front() << std::endl;
    std::cout<< "Array Back: " << arrVar.back() << std::endl;

    std::cout<< "Array Element 2: " << arrVar.at(2) << std::endl;       // Protection: Prevent access elements outside the defined size.

    for(auto& itr: arrVar) {
        std::cout<< itr << " ";
    }
}


void std_vector(void) {

    std::vector<int> vectVar_0(10);                             // Reserve size

    std::vector<int> vectVar_1 = {0, 10, 20, 30, 40, 50};       // Initializer List
    printVector(vectVar_1);

    std::vector<int> vectVar_2(vectVar_1);                      // Copy Constructor
    printVector(vectVar_2);

    std::vector<int> vectVar_3(std::move(vectVar_2));           // Move Constructor
    printVector(vectVar_3);

    std::vector<int> vectVar_4(5, 1);                           // Count and Value Constructor
    printVector(vectVar_4);

    /* Filling Constructor*/
    std::array<int, 5> arrVar = {99};
    std::vector<int> vectVar_5(arrVar.begin(), arrVar.end());
    printVector(vectVar_5);

    std::vector<int> vectVar_6(vectVar_4.begin(), vectVar_4.end());
    printVector(vectVar_6);

    std::initializer_list<int> vl {1, 2, 3, 4, 5};
    std::vector<int> vectVar_7(vl);
    printVector(vectVar_7);

    /*
        Functions of Vectors Almost same functions like std::array
    */
    vectVar_1.push_back(100);
    printVector(vectVar_1);

    vectVar_1.insert(vectVar_1.begin(), 20);
    printVector(vectVar_1);

    vectVar_1.emplace_back(300);                // Same as push_back ... but there is an optimization
    vectVar_1.emplace(vectVar_1.end(), 500);    // Same as insert ... but there is an optimization
    printVector(vectVar_1);


    std::cout<< vectVar_1.at(/* Index */1) << std::endl;
    std::cout<< vectVar_1.front() << " " << *(vectVar_1.begin()) << std::endl;      // First Element    end().. location of first element
    std::cout<< vectVar_1.back() << " " << *(vectVar_1.end()-1)<< std::endl;        // Last Element     end().. location after last element

    // trick in reverse iterator..
    std::cout<< *(vectVar_1.rend()-1) << std::endl;         // first Element  
    std::cout<< *(vectVar_1.rbegin()) << std::endl;         // last Element

    std::vector<int> vectVar_8(5, 5);
    vectVar_1.assign(vectVar_8.begin(), vectVar_8.end());
    printVector(vectVar_8);
    vectVar_8.erase(vectVar_8.begin(), vectVar_8.end());
    printVector(vectVar_1);
    printVector(vectVar_8);


    vectVar_1.resize(15);           // Expand 
    printVector(vectVar_1);
    vectVar_1.resize(9);            // Shrink
    printVector(vectVar_1);

    /*
        Size and Capacity
        Size: is the actual assigned size ...
        Capacity: is extra size reserved for vector but empty ... it is defined with an equation we can simplify it to be 2*size (at assignation)
        
        if resize occurs.
            - it will keep expand from reserved capacity ... until size == capcity.
            - if it exceeds, it will:
                - Erase Old Location in Heap.
                - Copy it to new location in Heap.
                - Expand Size as needed and Capcity 2*size
    */

    vectVar_1 = {0, 10, 20, 30, 40, 50, 100, 300, 500};
    printVector(vectVar_1);
    for(int i=0; i<33; i++) {
        vectVar_1.push_back(i);
        auto it = vectVar_1.cbegin().base();
        std::cout<< "Vector Begin Addr: " << it  << " - Size: " << vectVar_1.size() << " - Capacity: " << vectVar_1.capacity() << std::endl;
    }
}

void printVector(std::vector<int>& l_vect) {

    for(size_t l_itr : l_vect) {
        std::cout<< l_itr << " ";
    }
    std::cout<< std::endl;
}