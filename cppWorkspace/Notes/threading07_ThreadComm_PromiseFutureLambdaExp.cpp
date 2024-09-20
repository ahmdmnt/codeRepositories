#include <iostream>
#include <thread>
#include <future>

/*
    Threads Communication.
        - Communicate Data between threads ...
        using Promise and Future Objects in Lambda Expression
    
    Prmoise Object:
        - Have the ablility to be updated by any thread if passed in [closure capture]
        - reflect data in linked future object.
    Future Object:
        - Get Data from Thread-1 in Promise Object to MainThread in Future Object.
*/

int addFu(int l_num1, int l_num2) {
    std::cout<< "Thread-1 Terminates.." << std::endl;
    return l_num1 + l_num2;    
}

int main() {
    /* Create Promise Object */
    std::promise<int> promiseInstance;

    /* Create Future Object - link it to corresponding Promise Object */
    std::future<int> futureInstance = promiseInstance.get_future();


    /* Create Thread-1 */
    std::thread thread_1([&promiseInstance]() {
        /* Set function return in Promise Object */
        promiseInstance.set_value( addFu(5, 3) );
        /*
            VERY IMPORTANT
            I can do other operation ... set_value() is not a return .. 
        */

    });
    /* Joining Thread(s) to MainThread */
    thread_1.join();
    

    /* Read Data from Thread-1 using Future Object */
    int sumResult = futureInstance.get();               // IMPORTANT: it will WAIT, until the Promise Value is updated... to be able to get it into future
    std::cout<< "sumResult: " << sumResult << std::endl;

    std::cout<< "MainThread Terminates.." << std::endl;
    return 0;
}
