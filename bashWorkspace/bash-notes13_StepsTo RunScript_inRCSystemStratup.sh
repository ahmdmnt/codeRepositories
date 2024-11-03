#! /bin/bash

## For Extra Information on Bash: https://devhints.io/bash
###########################################################

## REVISE VIDEO: 03_Array_Getop_Files.mp4 @ 35:00
##################################################

# Script to Run at System Startup
################    My App to be run at Statrup -- NOTE:: Make sure it is working in its location normally // chmod +x log-system-on-date.sh
# log-system-on-date.sh -- in /usr/bin
#!/bin/sh
echo "[INFO]: System boots at $(date)" >> /system_on_log.txt
################
 
################    Make sure it is working in its location normally // chmod +x start-log-system-on.sh
# start-log-system-on.sh -- /etc/init.d
#!/bin/sh
 
case "$1" in
start)
    echo "Starting Log data on System on ..."
    /usr/bin/log-system-on-date.sh
    ;;
stop)
    kill pidof start-log-system-on.sh
    ;;
restart)
    $0 stop
    $0 start
    ;;
view)
    cat /system_on_log.txt
    ;;
*)
    echo "Usage: syslog { start | stop | restart | view }" >&2
    ;;
esac
################
 
# rc script will then run your script through a symbolic link created from your start script ... but link should have a prefix S##
# $ ln -s /etc/init.d/start-log-system-on.sh /etc/rc5.d/S##LogSystemBootTime.sh ... ## means order in running bwteen other scripts
# __OR__
# sudo update-rc.d myscript.sh defaults // Create Symbolic link for your script in current runlevel
