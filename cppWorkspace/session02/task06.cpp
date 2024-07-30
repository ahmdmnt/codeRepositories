/*
* Task 06:
*  Write a lambda function to calculate the square of a given number.
*/

#include <iostream>


int main() {

   auto fn = [] (int num) -> int {
      std::cout << "num = " << num << std::endl;
      return num*num;
   };


   int result = fn(10);
   std::cout << "num^2 = " << result << std::endl;

   return 0;
}
