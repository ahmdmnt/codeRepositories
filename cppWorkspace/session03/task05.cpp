/*
* Task 05:
* 	Handle Interrupt signal....
*     When i Press Ctrl+C >>> Code type any output note before aborting Application
*/
#include <iostream>
#include <csignal>
#include <unistd.h>



void signalHandler( int signum ) {
   std::cout << "Interrupt signal (" << signum << ") received." << std::endl;
   
   std::cout << "Application is aborting..." << std::endl;
   // terminate program  
   exit(signum);  
}

int main () {
   // register signal SIGINT and signal handler  
   signal(SIGINT, signalHandler);  

   while(1) {
      std::cout << "Up and Running..." << std::endl;
      sleep(1);
   }

   return 0;
}
