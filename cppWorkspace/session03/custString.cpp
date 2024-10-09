/*
* CLASS SOURCE FILE: myString
*/

#include <iostream>
#include "custString.hpp"

custString::custString(std::string l_str): strVariable(l_str) {

}

void custString::print(void) {
   std::cout<< strVariable << std::endl;
}

void custString::append(void) {
   
}

void custString::erase(void) {
   
}

void custString::replace(void) {
   
}

custString& custString::operator+=(const std::string& l_str) {
   this->strVariable += l_str;
   return *this;
}

custString& custString::operator+=(const custString& l_str) {
   this->strVariable += l_str.strVariable;
   return *this;
}

std::string operator+(const custString& strInstance, const std::string& l_str) {
   return strInstance.strVariable + l_str;
}

std::ostream& operator<<(std::ostream& l_cout, const custString& strInstance) {
    return l_cout << strInstance.strVariable;
}

int main() {

   custString myString("Ahmed Montasser");
   std::cout << myString << std::endl;

   std::string extraText = " Ramadan";
   std::cout<< myString + extraText << std::endl;

   myString += extraText;
   std::cout << myString << std::endl;

   custString myString2(" Mohamed");
   myString += myString2;
   std::cout << myString << std::endl;

   return 0;
}
