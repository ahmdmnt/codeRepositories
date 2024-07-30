/*
 * Task 05:
 *  Create a function to find the even and odd numbers in the array.
 */

#include <iostream>
#include <vector>
#include <algorithm>


int main() {

	std::vector<int> numList{10, 20, 1001, 2, -5, 100, 33, 51, 3000};

	std::vector<int> evenNumList {};
	std::vector<int> oddNumList {};
	for(int num: numList) {
		if(num%2 == 0) {
			evenNumList.insert(evenNumList.end(), num);
		}
		else {
			oddNumList.insert(oddNumList.end(), num);
		}
	}

	std::cout << "Even Numbers: ";
	for (int num : evenNumList) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	std::cout << " Odd Numbers: ";
	for (int num : oddNumList) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
    return 0;
}
