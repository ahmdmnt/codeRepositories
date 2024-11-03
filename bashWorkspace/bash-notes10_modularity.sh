#! /bin/bash

## For Extra Information on Bash: https://devhints.io/bash
###########################################################
 
 
 
## Modularity : Same like C-include
##################################### 
 
# Include lib.sh
source lib.sh     # the content of lib will be visible in my bash
# __OR__
# . lib.sh     # the content of lib will be visible in my bash


# use content of lib.sh
sayHello "Ahmed"
sayBye "Mohamed"