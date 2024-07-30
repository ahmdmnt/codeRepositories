/*
* Task 07:
*  Write a lambda functions to sort an array of integers in ascending and descending order.
*/

#include <iostream>
#include <vector>
#include <algorithm>


int main() {

   std::vector<int> numList {42, 51, 13, 50, 20, 33, 11, 7};

   /*
    *  lambda expression: Print Vector
    */
   auto printVector = [] (std::vector<int> vect) {
      for_each(vect.begin(), vect.end(), [](int num) {
            std::cout << num << " ";
         }
      );
      // for(int  num: vect) {
      //    std::cout << num << " ";
      // }
      std::cout << std::endl;
   };

   /*
    *  Ascending Sort Vector using lambda expression
    */
   std::sort(numList.begin(), numList.end(), [](const int& a, const int& b) -> bool {
      return a < b;
      }
   );
   std::cout<< " Ascending Order: ";
   printVector(numList);   

   /*
    *  Descending Sort Vector using lambda expression
    */
   std::sort(numList.begin(), numList.end(), [](const int& a, const int& b) -> bool {
      return a > b;
      }
   );
   std::cout<< "Descending Order: ";
   printVector(numList); 

   return 0;
}
