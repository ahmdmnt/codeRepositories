#!/usr/bin/python3

## Task: 7.0
### Get Ascii values of characters

for asciiValue in range(ord('A'), (ord('Z')+1)):
    print(f"|{chr(asciiValue) : ^10}|{asciiValue : ^10}|")

##########################################################