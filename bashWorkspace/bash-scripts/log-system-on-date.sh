#! /bin/bash

##     Script Name: log-system-on-date.sh 
##     Description: Log date of System PowerOn at each booting.
## Script Location: /usr/bin
################
# NOTE:: Make sure it is working in its location normally,
# $ chmod +x log-system-on-date.sh
################

echo "[INFO]: System boots at $(date)" >> "$HOME/system_on_log.txt"
################
