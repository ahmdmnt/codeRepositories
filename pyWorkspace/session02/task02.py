#!/usr/bin/python3

## Task: 2.0
### Get your current GPS location
import requests

getIpAddr = requests.get('https://api.ipify.org/?format=json')
ipAddr = getIpAddr.json()['ip']

fetchLocation = f"https://ipinfo.io/{ipAddr}/geo"
fetchLocation = requests.get(fetchLocation)

# print(fetchLocation.json())
print("City: ".rjust(11), fetchLocation.json()['city'])
print("Region: ".rjust(11), fetchLocation.json()['region'])
print("Country: ".rjust(11), fetchLocation.json()['country'])
print("Longitude: ", (str(fetchLocation.json()['loc'])).split(",")[1], "E")
print("Latitude: ".rjust(11), (str(fetchLocation.json()['loc'])).split(",")[0], "N")
# print("Location: ".rjust(11), fetchLocation.json()['loc'])
##########################################################