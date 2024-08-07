#include <iostream>
#include <regex>

/*
String Stream & Regex
    Parsing a string frame
*/

#include <iostream>
#include <sstream>

int main() {
    std::string stringFrame = "AhmedMontasser 30 Engineer 15.7";
    std::string name;
    int age;
    std::string jobTitle;
    double salary;

    std::stringstream stringParse(stringFrame);
    stringParse >> name >> age >> jobTitle >> salary;

    std::cout<< "     Name: " << name << std::endl;
    std::cout<< "      Age: " << age << std::endl;
    std::cout<< "Job Title: " << jobTitle << std::endl;
    std::cout<< "   Salary: " << salary << " K" << std::endl << std::endl;


    std::string stringSentence = "Hello, My Phone number is 01118883288 and email is ahmd.mnt@gmail.com";
    std::string emailAddress;
    int phoneNumber;

    std::regex emailAddrPattern("([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,6})");
    std::smatch emailMatch;
    std::regex_search(stringSentence, emailMatch, emailAddrPattern);
    std::cout<< "Extracted Email Address: " << emailMatch.str() << std::endl;

    std::regex phoneNumPattern("([0-9]+)");
    std::smatch phoneMatch;
    std::regex_search(stringSentence, phoneMatch, phoneNumPattern);
    std::cout<< " Extracted Phone Number: "<< phoneMatch.str() << std::endl;

    return 0;
}