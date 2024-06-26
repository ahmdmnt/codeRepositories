#!/usr/bin/python3

## Task: 5.0
### Prompt Battery Percentage and Make Notification [pyNotifier]

import psutil
# from pynotifier import Notification
from plyer import notification


# function returning time in hh:mm:ss 
def convertSecondsToTime(seconds): 
	minutes, seconds = divmod(seconds, 60) 
	hours, minutes = divmod(minutes, 60) 
	return "%d:%02d:%02d" % (hours, minutes, seconds) 


battery = psutil.sensors_battery() 
if battery is None:
	print("No Battery is found! Aborting...")
	quit()
else:
	batteryDescription = f"Battery percentage : {int(battery.percent)} %\n\nPlease Connect AC Adpater Plug!"
	print(batteryDescription)

	if(int(battery.percent) <= 25):
		notification.notify(
			title="Battery Percentage Warning",
			message=batteryDescription,
			timeout=20
		)
##########################################################