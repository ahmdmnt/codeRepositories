/*
* Task 01:
* Create a function to find the maximum number of array.
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

int main() {

	std::vector<int> numList{10, 20, 1000, 2, -5, 100};

	std::cout << "Max Element = " << *std::max_element(numList.begin(), numList.end()) << std::endl;

   return 0;
}
