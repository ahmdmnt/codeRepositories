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

void ThreadFu() {
    std::cout<< "Hello from another thread: Thread-1" << std::endl;

    /* Sleep function to allow Periodicity or Wait */
    std::cout<< "Thread-1 sleeps for 3 Second(s)... " << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    
    std::cout<< "Thread-1 Terminates.." << std::endl;
}



int main() {
    /* Create a Thread and pass for it - the desired function to be run throw it */
    std::thread thread_1(ThreadFu);


    #define JOIN_THREAD
    #ifdef JOIN_THREAD
    /* Join Thread-1 with MainThread ... to force MainThread to wait for Thread-1 until it finishes execution,
    then terminate itself after all joined threads finishes */
    thread_1.join();
    #endif

    // #define DETACH_THREAD
    #ifdef DETACH_THREAD
    /* Detach Thread-1 from MainThread ... MainThread will NOT wait for Thread-1 to finish execution,
    Main will terminate itself and then when thread finishes it will terminate afterworth */
    thread_1.detach();
    #endif

    /* Different Type of Sleep Function */
    #define TIME 1      // in seconds
    std::cout<< "MainThread sleeps for 1 Second(s)... " << std::endl;
    std::chrono::system_clock::time_point wakeUpTime = std::chrono::system_clock::now() + std::chrono::seconds(TIME);

    std::cout<< "MainThread Terminates.." << std::endl;
    return 0;
}
/*
    Check for Created Threads/Process in Linux
        # ps -auxH | grep -i a.out
*/