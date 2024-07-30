/*
* Task 04:
*  Create a function to merge two arrays together.
*/

#include <iostream>
#include <vector>
#include <algorithm>


int main() {

	std::vector<int> numList_1{10, 20, 1000, 2, -5, 100};
	std::vector<int> numList_2{30, 50, 3000, 300};


	std::vector<int> merged_numList(numList_1.size() + numList_2.size());
	std::merge(numList_1.begin(), numList_1.end(), numList_2.begin(), numList_2.end(), merged_numList.begin());

	std::cout << "Merged Vector: ";
	for (int num : merged_numList) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

   return 0;
}
