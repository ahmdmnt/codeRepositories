/*
* Task 09:
* 	Calculate the accumulate of array elements, without for loop.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {

   std::vector vec1 (20, 10);

   int arrSum {0};
   #define begin_end(ARR) ARR.begin(), ARR.end()
   std::for_each(begin_end(vec1), [&arrSum](int i) {
      arrSum += i;
   });

   std::cout<< "Sum of Array Elements= " << arrSum << std::endl;
   return 0;
}
