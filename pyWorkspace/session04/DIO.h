/**********************************************************************************************
 * DIO.h
 * 
 *		**DIO - Driver**
 *      Designed for AVR ATmega16 Microcontroller
 *
 *  Created on: Sep 6, 2020
 *      Author: Ahmed Montasser
 **********************************************************************************************
 * > When Using this Module :-
 * -----------------------------
 * 1. Set the port_name Value with below defines only:
 *      -DDR_A      -DDR_C      -DDR_B      -DDR_D
 *      -PIN_A      -PIN_C      -PIN_B      -PIN_D
 *      -PORT_A     -PORT_C     -PORT_B     -PORT_D
 * 
 * 2. Set the pin_name Value with below defines only:
 *      -PA0  -PA1  -PA2  -PA3  -PA4  -PA5  -PA6  -PA7
 *      -PB0  -PB1  -PB2  -PB3  -PB4  -PB5  -PB6  -PB7
 *      -PC0  -PC1  -PC2  -PC3  -PC4  -PC5  -PC6  -PC7
 *      -PD0  -PD1  -PD2  -PD3  -PD4  -PD5  -PD6  -PD7
 * 
 * 3. Set the direction Value with below defines only:
 *      -INPUT_PIN         -OUT_PIN
 *      -INPUT_PORT         -OUT_PORT
 * 
 * 4. Set the "value" Value with below defines only:
 *      -HIGH              -LOW
 * 
 **********************************************************************************************/

#ifndef DIO_H_
#define DIO_H_

/** Configuration Parameters ***************************************************/
/*** Defined Symbolic Constants ******/
#define INPUT_PIN 0
#define OUTPUT_PIN 1
#define INPUT_PORT 0
#define OUTPUT_PORT 1
/*** Static Configurations ******/    /* Edited By Developer */
/*****************************************************************************/

/** Used Directories *********************************************************/
#include "datatypes.h"
#include "macros.h"
#include "registers.h"
/*****************************************************************************/

/** Externed Global Variables ************************************************/
/*****************************************************************************/

/** Variables Declaration ****************************************************/
/*****************************************************************************/

/** Function Prototypes ******************************************************/

/**
 * @brief Adjust the DDR_x Registers for Desired PXX with needed direction
 * 
 * @param port_name 
 * @param pin_name 
 * @param direction 
 */
void  __DIO_setPinDirection(uint8 port_name,uint8 pin_name,uint8 direction);

/**
 * @brief Enable Internal Pullup Resistor for the Input Pin
 * 
 * @param port_name 
 * @param pin_name 
 */
void  __DIO_enableInternalPullupResistance(uint8 port_name,uint8 pin_name);

/**
 * @brief Output a Digital Value over the Output Pin
 * 
 * @param port_name 
 * @param pin_name 
 * @param value 
 */
void  __DIO_writeOutputPinValue(uint8 port_name,uint8 pin_name,uint8 value);

/**
 * @brief Read and fetch the Digital Value from a Pin
 * 
 * @param port_name 
 * @param pin_name 
 * @return uint8 
 */
uint8 __DIO_readInputPinValue(uint8 port_name,uint8 pin_name);

/**
 * @brief oggle the Value of Output Pin
 * 
 * @param port_name 
 * @param pin_name 
 */
void  __DIO_toggleOutputPinValue(uint8 port_name,uint8 pin_name);

/**
 * @brief Adjust the DDR_x Registers for Whole PORT with needed directio
 * 
 * @param port_name 
 * @param direction 
 */
void  __DIO_setPortDirection(uint8 port_name, uint8 direction);

/**
 * @brief Enable Internal Pullup Resistor for whole PORT Input Pins
 * 
 * @param port_name 
 */
void  __DIO_enablePortInternalPullupResistance(uint8 port_name);

/**
 * @brief Output Digital Values over the Output PORT Pins
 * 
 * @param port_name 
 * @param value 
 */
void  __DIO_writeOutputPortValue(uint8 port_name,uint8 value);

/**
 * @brief Read and fetch the Digital Values from PORT Pins
 * 
 * @param port_name 
 * @return uint8 
 */
uint8 __DIO_readInputPortValue(uint8 port_name);

/*****************************************************************************/
#endif /* DIO_H_ */