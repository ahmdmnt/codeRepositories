#!/bin/bash

## MY SCRIPT:
while true; do
    date >> "/home/ahmedmont/uptime_log.txt"
    sleep 1
done
#####################################################


## Implement Systemd Service:-
# 1- Write Systemd Service file into /lib/systemd/system/<SERVICE_FILENAME>.service
    # [Unit]
    # Description=<SCRIPT DESCRIPTION>
    # [Service]
    # ExecStart=<EXECUTABLE PATH and NAME>
    # [Install]
    # WantedBy=multi-user.target "For Example"

# 2- systemctl enable <SERVICE_FILENAME>.service    _____ service-filename -> symlink to /etc/systemd/system/<SERVICE_FILENAME> "Added into /etc/"
# 3- systemctl deamon-reload                        _____ "Re config all added services in systemd"
# 4- systemctl status <SERVICE_FILENAME>.service    _____ Check Status of Service
    # Active: inactive (dead)
# 5- systemctl start <SERVICE_FILENAME>             _____ start your service

# 6- [If i want to Edit .service file] 
    # $ sudo systemctl edit --full <SERVICE_FILENAME>.service
    # $ sudo systemctl restart <SERVICE_FILENAME>.service

# NOTE::: systemctl disable                         _____ symlink is deleted
#####################################################