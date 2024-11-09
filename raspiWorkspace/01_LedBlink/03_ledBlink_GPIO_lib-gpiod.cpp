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
 *  $ g++ -o blink ledblink_gpio_libgpiod.cpp -lgpiod
 *  $ sudo ./blink
*/
 
#include <gpiod.h>
#include <unistd.h>
#include <iostream>
 
int main() {
    const char *chipname = "gpiochip0";
    unsigned int line_num = 17;  // GPIO pin number
    unsigned int sleep_time = 1; // 1 second
 
    gpiod_chip *chip;
    gpiod_line *line;
    int ret;
 
    chip = gpiod_chip_open_by_name(chipname);
    if (!chip) {
        std::cerr << "Open chip failed\n";
        return -1;
    }
 
    line = gpiod_chip_get_line(chip, line_num);
    if (!line) {
        std::cerr << "Get line failed\n";
        gpiod_chip_close(chip);
        return -1;
    }
 
    ret = gpiod_line_request_output(line, "blink", 0);
    if (ret < 0) {
        std::cerr << "Request line as output failed\n";
        gpiod_chip_close(chip);
        return -1;
    }
 
    while (true) {
        gpiod_line_set_value(line, 1); // Turn on
        sleep(sleep_time);
        gpiod_line_set_value(line, 0); // Turn off
        sleep(sleep_time);
    }
 
    gpiod_chip_close(chip);
    return 0;
}