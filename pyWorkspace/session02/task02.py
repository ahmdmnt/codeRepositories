#!/usr/bin/python3

## Task: 2.0
### Get your current GPS location
import requests

getIpAddr = requests.get('https://api.ipify.org/?format=json')
ipAddr = getIpAddr.json()['ip']

fetchLocation = f"https://ipinfo.io/{ipAddr}/geo"
fetchLocation = requests.get(fetchLocation)

# print(fetchLocation.json())
print("City: ".rjust(10), fetchLocation.json()['city'])
print("Region: ".rjust(10), fetchLocation.json()['region'])
print("Country: ".rjust(10), fetchLocation.json()['country'])
print("Location: ", fetchLocation.json()['loc'])
##########################################################