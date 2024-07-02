#!/usr/bin/python3

## Example: Client Code

import socket

socketClient = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ipAddr = socket.gethostbyname(socket.gethostname())
print("My IP: ",ipAddr)
print("---------------------------------")

socketClient.connect((ipAddr, 5000))
sndData = (str(input("Enter Send Message: "))).encode()
socketClient.send(sndData)
print("---------------------------------")

rcvData = socketClient.recv(1024)
print(f"[{ipAddr}] sends: {rcvData.decode()}")
print("---------------------------------")
socketClient.close()
##########################################################