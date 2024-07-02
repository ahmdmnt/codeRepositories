#!/usr/bin/python3

## Task: Server Code

import socket
import threading


# Server settings
HOST = socket.gethostbyname(socket.gethostname())       # Wifi-LAN
PORT = 5000                                             # Port to listen on
############################################################################

# Function to handle client connections
def handle_client(client_socket, client_address):
    print(f"[NEW CONNECTION] {client_address} connected.")
    connected = True
    while connected:
        try:
            # Receive message from the client
            message = client_socket.recv(1024).decode('utf-8')
            if message == 'exit':
                connected = False
            else:
                print(f"[{client_address}] {message}")
                # Send the message back to the client (echo)
                # client_socket.send(f"Server received: {message}".encode('utf-8'))
        except:
            connected = False
    client_socket.close()
    print(f"[DISCONNECTED] {client_address} disconnected.")

# Main function to start the server
def start_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((HOST, PORT))
    server.listen()
    print(f"[LISTENING] Server is listening on {HOST}:{PORT}")
    while True:
        client_socket, client_address = server.accept()
        thread = threading.Thread(target=handle_client, args=(client_socket, client_address))
        thread.start()
        print(f"[ACTIVE CONNECTIONS] {threading.active_count() - 1}")

if __name__ == "__main__":
    start_server()
##########################################################