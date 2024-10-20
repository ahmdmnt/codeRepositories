#! /bin/bash

## Open most-common used folders
value="${HOME}/_embeddedLinux\n${HOME}/_GitHub"
selected=$(echo -e "$value" | rofi -dmenu)
nautilus "$selected" &  