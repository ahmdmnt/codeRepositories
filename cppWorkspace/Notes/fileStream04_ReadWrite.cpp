#include <iostream>
#include <fstream>
#include <array>
#include <vector>

/*
    File Stream.
        - Accessing Different Files.
*/

int main() {  
    
    /* Create File Instance - for Read */
    std::fstream fileInstance("example_write.txt", std::ios::in|std::ios::out);

    /* Check if Opened, and no Issues */
    if(fileInstance.is_open()) {
        std::cout<< "Successful File open!" << std::endl;

        /* Write Text in file */
        fileInstance << "This is FIRST added line from C++ SW Program." << std::endl;
        fileInstance.write("This is SECOND added line from C++ SW Program.\n", 47);      // Count of Letters to be written
        fileInstance.flush();       // Process All Buffered Data
    }
    else {
        std::cout<< "ERROR: Failed to Open File!!" << std::endl;
    }

    /* Close File Instance */
    fileInstance.close();

    return 0;
}
