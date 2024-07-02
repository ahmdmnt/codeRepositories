#!/usr/bin/python3

## Example: Server Code

import socket

socketServer = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
ipAddr = socket.gethostbyname(socket.gethostname())
print("My IP: ",ipAddr)
print("---------------------------------")

socketServer.bind((ipAddr, 5000))
socketServer.listen(5)

while True:
    client, clientAddr = socketServer.accept()    # Waiting until a client connects
    rcvData = client.recv(1024)
    print(f"[{clientAddr[0]}] sends: {rcvData.decode()}")
    print("---------------------------------")
    sndData = (str(input("Enter Send Message: "))).encode()
    print("---------------------------------")
    client.send(sndData)
    client.close()
##########################################################