#include <iostream>
#include <thread>
#include <mutex>

/*
    Mutex: (std::mutex)
       - to Protect shared Resource
*/

std::mutex mtx;
int count = 0;

void ThreadFu() {
    mtx.lock();
    for(int i=0; i<100000; i++) {
        count++;
    }
    mtx.unlock();
}

int main() {
    
    /*
        Race condition:
            when multiple threads manupalute a Shared Resource, thread can be interrupted before correctly handle the SharedResoucre ...
            Proctection is needed.
    */
    std::thread thread_1(ThreadFu);
    std::thread thread_2(ThreadFu);
    std::thread thread_3(ThreadFu);

    /* Joining Threads to MainThread */
    thread_1.join();
    thread_2.join();
    thread_3.join();

    std::cout<< "Count: " << count << std::endl;        // it won't have the correct value each run time.
    std::cout<< "MainThread Terminates.." << std::endl;
    return 0;
}
