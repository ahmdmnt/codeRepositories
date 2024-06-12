#!/usr/bin/python3

## Task: 1.0
### Open your favourite websites, using command line args 
#### facebook, udemy, etc..
import sys
import firelink

inputWebsite = (str(sys.argv[1])).lower()

firelink.firefox(inputWebsite)
while True:
    pass
##########################################################