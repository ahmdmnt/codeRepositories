/*
* Task 02:
*  Create a function to search to the number in the array which number is taken from user.
*/

#include <iostream>
#include <vector>
#include <algorithm>


int main() {

	std::vector<int> numList{10, 20, 1000, 2, -5, 100};

	std::cout<< "Enter the desired number: ";
	int inputNum;
	std::cin>> inputNum;

	auto numIndex= std::find(numList.begin(), numList.end(), inputNum);

	if(numIndex != numList.end()) {
		std::cout << "Element (" << inputNum <<  ") found at Index : " << numIndex - numList.begin() << std::endl;
	}
	else {
		std::cout<< "Element not found!" << std::endl;
	}
   return 0;
}
