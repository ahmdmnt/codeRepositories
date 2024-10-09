/*
* Task 08:
* 	try using and and or keywords
*/

#include <iostream>
#include <array>

int main() {

   std::array<int, 10> arr1 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
   
   if( (arr1[0]==0) and (arr1[9]==9) )
      std::cout << "Subsequent Array" << std::endl;

   if( (arr1[0]==0) or (arr1[9]==9) )
      std::cout << "Integer Array" << std::endl;

   return 0;
}
