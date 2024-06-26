#!/usr/bin/python3

## Task: 3.0
### Generate Init Function for AVR GPIO - According to CSV file

import csv

def set_bit(value, bit):
    return value | (1<<bit)

def clear_bit(value, bit):
    return value & ~(1<<bit)

FILE_PATH = "DioConfig.csv"
DDRA = 0x00
PORTA = 0x00
PINA = 0x00

with open(FILE_PATH, mode ='r')as dioConfigFile:
    dioConfigCSV = csv.reader(dioConfigFile, delimiter=',')
    line_count = 0
    for dioConfig in dioConfigCSV:

        if(dioConfig[1] == "out"):
            DDRA = set_bit(DDRA, int(dioConfig[0]))
            
            if(dioConfig[2] == "high"):
                PORTA = set_bit(PORTA, int(dioConfig[0]))
            elif(dioConfig[2] == "low"):
                PORTA = clear_bit(PORTA, int(dioConfig[0]))

        if(dioConfig[1] == "in"):
            DDRA = clear_bit(DDRA, int(dioConfig[0]))


            if(dioConfig[2] == "pullup"):
                PINA = set_bit(PINA, int(dioConfig[0]))
            elif(dioConfig[2] == "pulldown"):
                PINA = clear_bit(PINA, int(dioConfig[0]))

print(bin(DDRA))
print(bin(PORTA))
print(bin(PINA))

##########################################################