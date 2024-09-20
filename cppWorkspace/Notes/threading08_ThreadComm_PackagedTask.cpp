#include <iostream>
#include <thread>
#include <future>

/*
    Threads Communication.
        - Communicate Data between threads ...
        using Packaged Task

*/

int addFu(int l_num1, int l_num2) {
    std::cout<< "Thread-1 Terminates.." << std::endl;
    return l_num1 + l_num2;    
}

int main() {
    /* Create Packaged Task */
    std::packaged_task<int(int, int)> task_1(addFu);    // std::packaged_task<<FUNCTION_SIGNATURE>> <TASK_NAME>(<FUNCTION_NAME>);

    /* Create Future Object - link it Packaged Task */
    std::future<int> futureInstance = task_1.get_future();      // VERY IMPORTANT .. it simulate RETURN BEHAVIOUR


    /* Create Thread-1 */
    std::thread thread_1(std::move(task_1), 5, 4);      // std::thread <THREAD_NAME>(std::move(<TASK_NAME>), <ARGS...>);
    /* Joining Thread(s) to MainThread */
    thread_1.join();
    

    /* Read Data from Thread-1 using Future Object */
    int sumResult = futureInstance.get();               // IMPORTANT: it will WAIT, until the Promise Value is updated... to be able to get it into future
    std::cout<< "sumResult: " << sumResult << std::endl;

    std::cout<< "MainThread Terminates.." << std::endl;
    return 0;
}
