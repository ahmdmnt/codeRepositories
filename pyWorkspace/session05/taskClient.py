#!/usr/bin/python3

## Task: Client Code

from time import sleep
import random
import socket


# Server settings
HOST = socket.gethostbyname(socket.gethostname())       # Wifi-LAN
PORT = 5000                                             # Port to listen on
#############################################################################

def start_client():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((HOST, PORT))
    print(f"[CONNECTED] Connected to server at {HOST}:{PORT}")
    
    clientID = random.choice(range(5))
    clientMessages = [f"Hello, this is Client {clientID}!", "exit"]
    for message in clientMessages:
        client.send(message.encode('utf-8'))
        sleep(3)
        if message == 'exit':
            break

    client.close()
    print("[DISCONNECTED] Disconnected from the server.")

if __name__ == "__main__":
    start_client()
##########################################################