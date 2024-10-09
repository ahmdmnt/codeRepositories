/*
* Task 02:
*	using Class
*		Check if all array is even
*/

#include <iostream>

#define ARR_SIZE 5

class myArray {
   int* arrPtr=nullptr;
   int size;
public:
   myArray(int* l_ptr, int l_size) : arrPtr(l_ptr), size(l_size) {}
   void printMyArray(void) {
      for(int itr=0; itr<size; itr++) {
         std::cout<< arrPtr[itr] << " ";
      }
      std::cout<< std::endl;
   }
   bool checkElementsAreEven(void) {
      for(int itr=0; itr<size; itr++) {
         if( arrPtr[itr]%2!=0 ) {
            return false;
         }
      }
      return true;
   }
};

int main() {

   int arr1[ARR_SIZE] {1,2,3,4,5};
   int arr2[ARR_SIZE] {2,4,6,8,10};

   std::cout<< std::boolalpha;

   myArray myArr1(arr1, ARR_SIZE);
   myArr1.printMyArray();
   std::cout<< "All Elements in Array are Even: " << myArr1.checkElementsAreEven() << std::endl;

   myArray myArr2(arr2, ARR_SIZE);
   myArr2.printMyArray();
   std::cout<< "All Elements in Array are Even: " << myArr2.checkElementsAreEven() << std::endl;

   return 0;
}
