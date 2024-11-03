#! /bin/bash

## SCRIPT DESCRIPTION
# Check Connected devices on your Network
##########################################
 
for i in {1..254}; do
    ping -c 1 -W 1 "192.168.1.$i" > /dev/null   # Discard the output of command
    # ping -c 1 -W 1 "192.168.1.$i" 2> /dev/null > /dev/null   # Discard the output of command and Std::Errors
    if [ $? -eq 0 ]; then   # if the Output is 0 this mean it is connected
        echo -e "\e[32m[192.168.1.$i]\e[0m is connected to the Network"
    fi
done