#!/usr/bin/python3

## Task: 6.0
### Get Commandline Arguments

import sys


print(f"sys.argv[]= {sys.argv[:]}\nsys.argv[].type= {type(sys.argv)}\n")
print("Script Name is:", sys.argv[0])
print("Arguments are:", sys.argv[1:])

##########################################################