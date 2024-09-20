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
    std::fstream fileInstance("a.out", std::ios::in|std::ios::binary);      // std::ios::binary [Optional]

    /* Check if Opened, and no Issues */
    if(fileInstance.is_open()) {
        std::cout<< "Successful File open!" << std::endl;

        /* Read Binaries */
        std::array<char, 16> bufferVariable;
        fileInstance.read(bufferVariable.data(), bufferVariable.size());
        for(auto byte: bufferVariable) {
            std::printf("%02x ", static_cast<unsigned char>(byte));
        }
        std::cout<< std::endl;
        /* File Size in Bytes*/
        std::cout<< "Total Count of Bytes: " << fileInstance.gcount() << std::endl;
    }
    else {
        std::cout<< "ERROR: Failed to Open File!!" << std::endl;
    }

    /* Close File Instance */
    fileInstance.close();

    return 0;
}
