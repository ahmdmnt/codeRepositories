/*
* CLASS SOURCE FILE: myString
*/

#include <iostream>
#include "myString.hpp"


void myString::display () {
   std::cout<< message << std::endl;
}

myString& myString::operator+=(const std::string& msg) {
   this->message += msg;
   return *this;   //myStringInstance
}

bool myString::operator<(const myString& dInstance) {
   return this->message < dInstance.message;
}


std::string operator+(const myString& dInstance, const std::string& msg) {
    return dInstance.message + msg;
}
