#include <iostream>
#include <fstream>

/*
    File Stream.
        - Accessing Different Files.
*/

int main() {  
    
    /* Create File Instance - for Read */
    std::fstream fileInstance("example.txt", std::ios::in);

    /* Check if Opened, and no Issues */
    if(fileInstance.is_open()) {
        std::cout<< "Successful File open!" << std::endl;

    }
    else {
        std::cout<< "ERROR: Failed to Open File!!" << std::endl;
    }

    /* Move File Instance - (IMP) and close old instance automatically after moving */
    std::fstream fileInstance_2 = std::move(fileInstance);

    /* check file opened before Read Operation */
    if(fileInstance_2.is_open()) {
        /* Read All File Data */
        std::streambuf* readBuffer = fileInstance_2.rdbuf();
        std::cout<< readBuffer << std::endl;
    }

    /* Close File Instance */
    fileInstance_2.close();

    return 0;
}
