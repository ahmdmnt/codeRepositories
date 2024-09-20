#include <iostream>
#include <thread>
#include <vector>

/*
    Threading:
        > std::thread()
    SW is handled with different threads in Parallel
        - main thread.
        - multiple another threads.
*/

void ThreadFu(std::string l_name) {
    std::cout<< "Thread-1 sleeps for 1 Second(s)... " << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout<< "Hello (" << l_name << ") from Thread-1" << std::endl;
    std::cout<< "Thread-1 Terminates.." << std::endl;
}


/*  Class with Functor  */
class myClassFunctor {
public:
    // Functor Definition
    void operator()(int l_num) {
        std::cout<< "Thread-2 sleeps for 2 Second(s)... " << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::cout<< "My Functor Argument: " << l_num << std::endl;
        std::cout<< "Thread-2 Terminates.." << std::endl;
    }
};


int main() {
    int offset{1};
    
    /* Function Call with Arguments */
    std::thread thread_1(ThreadFu, "Ahmed");

    /* Class-Functor Call with Arguments */
    std::thread thread_2(myClassFunctor(), 120);

    /* Lambda Expression Call */
    std::thread thread_3( [&offset](int l_num1, int l_num2) {
        std::cout<< "Thread-3 sleeps for 3 Second(s)... " << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));

        std::cout<< "Summation: " << l_num1+l_num2+offset << std::endl;
        std::cout<< "Thread-3 Terminates.." << std::endl;
    }, 120, 30 );

    /* Joining Threads to MainThread */
    thread_1.join();
    thread_2.join();
    thread_3.join();

    std::cout<< "MainThread Terminates.." << std::endl;
    return 0;
}
