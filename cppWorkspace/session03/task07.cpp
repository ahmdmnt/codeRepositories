/*
* Task 07:
* 	Fill Array from 10 to 10000 sequentially
*     {10, 11, 12, ....., 10,000}
*/

#include <iostream>
#include <array>
#include <numeric>
#include <algorithm>

int main() {

   std::array<int, 9991> arr1;

   std::iota(arr1.begin(), arr1.end(), 10);

   for(auto i: arr1) {
      if(i<14 || i>9996)
         std::cout<< i << " ";
      else if( i==15 )
         std::cout << "... ";
   }

   std::cout << std::endl;

   int val {10};
   std::generate(arr1.begin(), arr1.end(), [&val]() {
      return val++;
   });

   #define begin_end(ARR) ARR.begin(), ARR.end()
   std::for_each(begin_end(arr1), [](int i) {
      if(i<14 || i>9996)
         std::cout<< i << " ";
      else if( i==15 )
         std::cout << "... ";
   });

   return 0;
}
