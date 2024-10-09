/*
* Task 06:
* 	How to Handle Calling Function in lvalue
*      fn() = 10;
*/

#include <iostream>

int g_variable = 0;

int& g_fn() {
   return g_variable;
} 

int& fn() {
   static int myVariable;
   return myVariable;
} 

int main() {

   fn() = 5;
   std::cout << "Value of fn() = " << fn() << std::endl;

   g_fn() = 100;
   std::cout << "Value of g_fn() = " << g_fn() << std::endl;
   std::cout << "Value of g_variable = " << g_variable << std::endl;

   return 0;
}
