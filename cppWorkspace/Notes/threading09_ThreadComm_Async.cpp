#include <iostream>
#include <thread>
#include <future>

/*
    Threads Communication.
        - Communicate Data between threads ...
        using Async (Easier Implementation)
            - No need for either Promise or Packaged Task.

*/

int addFu(int l_num1, int l_num2) {
    std::cout<< "Thread-1 Terminates.." << std::endl;
    return l_num1 + l_num2;    
}

int main() {  
    /* Launch "Async" - Get Thread Return in Defined Furture Object at same Line, 
        - Same Line does:-
            - Create Future Object.
            - Create a Thread.
            - Link them Together.
            - Update Future with return Value.  -->> (IMP.. it simulate RETURN BEHAVIOUR).
        - No need to link ".get_future()".
        - No need to Join/Detach with/from MainThread (done automatically).
    */
    std::future<int> futureInstance = std::async(std::launch::async, addFu, 5, 5);     // std::async(std::launch::async, <FUNCTION NAME>, <ARGs...>); 

    /* Read Data from Thread-1 using Future Object */
    int sumResult = futureInstance.get();               // IMPORTANT: it will WAIT, until the Promise Value is updated... to be able to get it into future
    std::cout<< "sumResult: " << sumResult << std::endl;

    std::cout<< "MainThread Terminates.." << std::endl;
    return 0;
}
