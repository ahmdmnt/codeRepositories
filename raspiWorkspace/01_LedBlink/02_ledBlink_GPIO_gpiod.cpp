/**
 * Example for Out GPIO Pin - Raspberry PI :
 *  DESCRIPTION : Led Blinking - Using gpiod
 *
 *  - Check if the Pin is available or in Use "it should be unused".
 *      $ gpioinfo
 *
 *  - Check Value of a INPUT PIN :: gpioget <CHIP_NUMBER> <PIN_NUMBER>
 *      $ gpioget gpiochip0 20
 *
 *  - Set Value of a OUTPU PIN :: gpioset <CHIP_NUMBER> <PIN_NUMBER>=<VALUE>
 *      $ gpioset gpiochip0 20=1
 */
 
/**
 *  $ g++ -o blink ledblink_gpio_gpiod.cpp
 *  $ sudo ./blink
 */
 
#include <iostream>
#include <unistd.h>
#include <cstdlib> // For system()
 
int main() {
    const char* chipname = "gpiochip0";
    unsigned int line_num = 17; // GPIO pin number
    unsigned int sleep_time = 1; // 1 second
 
    while (true) {
        // Turn the LED on
        std::string on_cmd = "gpioset " + std::string(chipname) + " " + std::to_string(line_num) + "=1";
        system(on_cmd.c_str());
        sleep(sleep_time);
 
        // Turn the LED off
        std::string off_cmd = "gpioset " + std::string(chipname) + " " + std::to_string(line_num) + "=0";
        system(off_cmd.c_str());
        sleep(sleep_time);
    }
 
    return 0;
}