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
    std::fstream fileInstance("example.txt", std::ios::in);

    /* Check if Opened, and no Issues */
    if(fileInstance.is_open()) {
        std::cout<< "Successful File open!" << std::endl;

    }
    else {
        std::cout<< "ERROR: Failed to Open File!!" << std::endl;
    }

    /* Bits Types
        - State Bit :  
        - Good Bit  : No Errors - Bit Position (0)      - Value(True)=OK   & Value(False)= NOK.
        - Bad Bit   : Irrecoverable Stream Error        - Bit Position (1) - Value(True)=NOK  & Value(False)= OK.
        - EOF Bit   : InputSeq has reached end of file  - Bit Position (2) - Value(True)=NOK  & Value(False)= OK.
        - Fail Bit  : In/Out Operation failed           - Bit Position (4) - Value(True)=NOK  & Value(False)= OK.
    */
    std::cout<< std::boolalpha;
    std::cout<< "Status Value: " << fileInstance.rdstate() << std::endl;        
    std::cout<< "BitPosition: " << std::fstream::goodbit << " - Bit Value: "<< fileInstance.good() << std::endl;    
    std::cout<< "BitPosition: " << std::fstream::badbit << " - Bit Value: "<< fileInstance.bad() << std::endl;
    std::cout<< "BitPosition: " << std::fstream::eofbit << " - Bit Value: "<< fileInstance.eof() << std::endl;
    std::cout<< "BitPosition: " << std::fstream::failbit << " - Bit Value: "<< fileInstance.fail() << std::endl;

    /* Simulate EOF Issue - Set Cursor at EOF and try to Read */
    fileInstance.seekg(0, std::ios::end);
    char let = fileInstance.get();
    if(fileInstance.eof()) {
        std::cout<< "Error: Cannot read, File Reached its end" << std::endl;
    }

    /* Close File Instance */
    fileInstance.close();

    return 0;
}
