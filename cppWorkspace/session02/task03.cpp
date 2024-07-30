/*
* Task 03:
*  Create a function to delete number in array.
*/

#include <iostream>
#include <vector>
#include <algorithm>


int main() {

	std::vector<int> numList{10, 20, 1000, 2, -5, 100};

	int deletedNum {1000};


   auto numIdx = std::find(numList.begin(), numList.end(), deletedNum);
   if (numIdx != numList.end()) {
   	numList.erase(numIdx);
   }

   std::cout << "Vector After Number Deletion: ";
   for (int element : numList) {
   	std::cout << element << " ";
   }
   std::cout << std::endl;

   return 0;
}
