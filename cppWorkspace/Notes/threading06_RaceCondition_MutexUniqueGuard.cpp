#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int count = 0;

/*
    Unique Lock (std::unique_lock)
        - Locking and Unlocking Lock Guard
*/

void ThreadFu() {
    /*
        it will lock and unlock will be done automatically "RAII".
        - It won't unlock until the whole function finishes... this is other Issue (Locking time big and no need for that)/
    */
    std::unique_lock<std::mutex> lock(mtx);
    for(int i=0; i<100000; i++) {
        count++;
    }
    lock.unlock();

    /*
        ....Doing another Operations....
    */

    lock.lock();        // Lock the Guard again
    count*= 2; 
    // lock.unlock();      // Unlock again  -- Not needed becuz function terminates and RAII ... with automatically unlock.
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
