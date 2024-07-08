/*
 * Task 04:
 * Decide the letter is vowel or not
 */

#include <iostream>

int main() {

    char inputChar;
    std::cout<< "Enter a letter: ";
    std::cin>> inputChar;

    inputChar = std::tolower(inputChar);
    if(inputChar=='a' || inputChar=='e' || inputChar=='o' ||
    inputChar=='u' || inputChar=='i') {
        std::cout<< "The Letter is Vowel." << std::endl;
    }
    else {
        std::cout<< "The Letter is Consonant." << std::endl;
    }
    
    return 0;
}