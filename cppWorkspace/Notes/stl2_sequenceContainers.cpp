#include <iostream>
#include <deque>


/*
    DEQUE:  Double Ended Queue
        Syntax: 
            std::deque
        
        Not very good practice in Memory ... allow simple and efficient deletion and insertion operations ... Front and Back

        Array "1st element is Queue size" and reset is Pointers pointing to each element in Queue arranged subsequently.
        which gives u the flexibity to add and delete element from beginning and end.
*/
/*
    LIST:
        Syntax: 
            std::list

        Similar to Double linked list in Data structure but implemented already in CPP STL.
            Front or Back handling of list.
*/
/*
    FORWARD_LIST:
        Syntax: 
            std::forward_list

        Similar to SINGLE linked list in Data structure but implemented already in CPP STL.
            Front ONLY handling of list.
*/


void print(std::deque<int>& l_deque);

int main() {

    std::deque<int> queVar (5, 0);

    queVar.push_front(10);
    queVar.push_front(20);
    queVar.push_back(20);
    queVar.push_back(10);
    print(queVar);

    queVar.pop_front();
    queVar.pop_back();
    print(queVar);


    return 0;
}

void print(std::deque<int>& l_deque) {
    for(int ele: l_deque) {
        std::cout << ele << " ";
    }
    std::cout<< std::endl;
};