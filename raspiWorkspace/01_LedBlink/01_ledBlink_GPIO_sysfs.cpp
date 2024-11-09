/**
 * Example for Out GPIO Pin - Raspberry PI :
 *  DESCRIPTION : Led Blinking - Using sysfs (sys FileSystem)
 *
 *  1. move to dir
 *      $ cd /sys/class/gpio
 *  2. check if the Pin is available or in Use "it should be unused".
 *      $ gpioinfo | grep 20
 *  3. export the Pin to be used - gpio20 Directory with its content will be created
 *      $ echo 20 > export
 *  4. set "out" value in direction file
 *      $ echo out > direction
 *  5. set "1"/"0" value in value file
 *      $ echo 1 > value
 *  -----------------------------------
 *  6. to Unuse the Pin back again
 *      $ echo 20 > unexport
 *
 * EXTRA INFORMATION :
 * www.github.com/raspberrypi/linux
 */
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
 
#define EXPORT_FILEPATH "/sys/class/gpio/export"
#define DIRECTION_FILEPATH "/sys/class/gpio/gpio20/direction"
#define VALUE_FILEPATH "/sys/class/gpio/gpio20/value"
#define PIN_NUMBER      "20"
#define PIN_DIRECTION   "out"
#define PIN_HIGH        "1"
#define PIN_LOW         "0"
 
void pinExport_init();
void pinDirection_init();
void pinValue_ToggleLedApp();
 
int main() {
 
    pinExport_init();
    pinDirection_init();
    pinValue_ToggleLedApp();
}
 
void pinExport_init() {
    int file;
 
    /* Set Export file for GPIO 20 */
    file = open(EXPORT_FILEPATH, O_WRONLY);
    if( file == -1) {   /* File not Opened*/
        std::cout<< "ERROR, File can't be opened!" << std::endl;
    }
    write(file, PIN_NUMBER, strlen(PIN_NUMBER));
    close(file);
    sleep(1);
}
 
void pinDirection_init() {
    int file;
   
    /* Set Direction as out */
    if( !access(DIRECTION_FILEPATH, F_OK) ) {     /* Make sure the File is available */
        file = open(DIRECTION_FILEPATH, O_WRONLY);
        if( file == -1) {   /* File not Opened*/
            std::cout<< "ERROR, File can't be opened!" << std::endl;
        }
        write(file, PIN_DIRECTION, strlen(PIN_DIRECTION));
        close(file);
        sleep(1);
    }
}
 
void pinValue_ToggleLedApp() {
    int file;
 
    /* Toggle Led Value for 5 times */
    file = open("/sys/class/gpio/gpio20/value", O_WRONLY);
    if( file == -1) {   /* File not Opened*/
        std::cout<< "ERROR, File can't be opened!" << std::endl;
    }
    for(int i=0 ; i<5 ; i++) {
        write(file, PIN_HIGH, strlen(PIN_HIGH));
        sleep(2);
        write(file, PIN_LOW, strlen(PIN_LOW));
        sleep(2);
    }
    close(file);
    sleep(1);
}