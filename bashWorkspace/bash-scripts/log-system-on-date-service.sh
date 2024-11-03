#! /bin/bash


#     Script Name: log-system-on-date-service.sh
# Script Location: /etc/init.d
################    
# NOTE: Make sure it is working in its location normally,
# $ chmod +x start-log-system-on.sh
################

case "$1" in
start)
    echo "Starting Log data on System on ..."
    /usr/bin/log-system-on-date.sh
    ;;
view)
    cat "$HOME/system_on_log.txt"
    ;;
clear)
    echo "Cleanup! Deleting Log data file ..."
    rm "$HOME/system_on_log.txt"
    ;;
*)
    echo "Usage: syslog { start | view | clear }" >&2
    ;;
esac
################
 
# rc script will then run your script through a symbolic link created from your start script ... but link should have a prefix S##
# $ ln -s ../init.d/start-log-system-on.sh start /etc/rc5.d/S99LogSystemBootTime.sh ... ## means order in running bwteen other scripts
# __OR__
# sudo update-rc.d myscript.sh defaults // Create Symbolic link for your script in current runlevel