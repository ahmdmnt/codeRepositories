#!/usr/bin/python3

## Task: 5.0
### Prompt Battery Percentage and Make Notification [pyNotifier]

import psutil
from pynotifier import Notification

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
	print(f"Battery percentage : {int(battery.percent)} %") 
	print(f"Power plugged in : {battery.power_plugged}")
	if (battery.power_plugged == False):
		print(f"Battery left : {convertSecondsToTime(battery.secsleft)}")

batteryDescription = f"Battery percentage : {int(battery.percent)} %\nBattery left : {convertSecondsToTime(battery.secsleft)}\nPlease Connect AC Adpater Plug!"
print(batteryDescription)
Notification(
	title="Battery Precentage Warning",
	description=batteryDescription,
	duration=10,
	urgency='normal'
).send()
##########################################################