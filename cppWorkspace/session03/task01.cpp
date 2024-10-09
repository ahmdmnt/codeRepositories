/*
* Task 01:
* 	using Class
*		Check if the Character is digit
*/

#include <iostream>

class myChar {
   char c_variable = 0;

public:
   myChar(char l_char): c_variable(l_char) {}
   
   bool characterIsDigit() {
      if(c_variable>='0' && c_variable<='9') {
         return true;
      }
      return false;
   }
};

int main() {
   std::cout<< std::boolalpha;
   
   myChar myChar1('a');
   std::cout<< "characterIsDigit: " << myChar1.characterIsDigit() << std::endl;

   myChar myChar2('#');
   std::cout<< "characterIsDigit: " << myChar2.characterIsDigit() << std::endl;

   myChar myChar3('0');
   std::cout<< "characterIsDigit: " << myChar3.characterIsDigit() << std::endl;

   myChar myChar4('7');
   std::cout<< "characterIsDigit: " << myChar4.characterIsDigit() << std::endl;

   return 0;
}
