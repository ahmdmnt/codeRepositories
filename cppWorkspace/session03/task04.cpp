/*
* Task 04:
* 	using Class
*		Write string class which has Members {length - string}
*/

#include <iostream>
#include <string.h>

class myString {
   char* str = nullptr;
public:
   myString(char* l_str) : str(l_str) {}
   int length() {
      int length = -1;
      if( str != nullptr ) {
         length = strlen(str);
      }
      else {
         std::cout<< "Error: String Object is not initialized!" << std::endl;
      }
      return length;
   }
};

int main() {

   char* str1 = "AhmedMontasser";

   myString myStr1(str1);
   std::cout<< "String Length = " << myStr1.length() << std::endl;

   return 0;
}
