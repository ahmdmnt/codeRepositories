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

    /* Read 1st Character and Move Cursor Step-forward */
    char letter = fileInstance.get();
    std::cout<< "Letter: " << letter << std::endl;  

    /* Read 2nd Character and Move Cursor Step-forward */
    letter = fileInstance.get();
    std::cout<< "Letter: " << letter << std::endl;

    /* Read line in file */
    std::array<char, 50> charArray;         
    fileInstance.getline(charArray.data(), 20);     // Read Buffer Size
    std::cout<< "Line: " << charArray.data() << std::endl;

    /* Seek funtion -- seekg(Offset, StartPosition)
        Position Types:
            - std::ios::beg     : Begin of File
            - std::ios::end     : End of File
            - std::ios::cur     : Cursor Current Position
    */
    fileInstance.seekg(0, std::ios::beg);
    std::cout<< "Char seekg(): " << static_cast<char>(fileInstance.get()) << std::endl;
    fileInstance.seekg(3, std::ios::cur);
    std::cout<< "Char seekg(): " << static_cast<char>(fileInstance.get()) << std::endl;
    fileInstance.seekg(-2, std::ios::end);
    std::cout<< "Char seekg(): " << static_cast<char>(fileInstance.get()) << std::endl;

    /* Close File Instance */
    fileInstance.close();
    
    return 0;
}