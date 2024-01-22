# server.py
import socket

PORT = 8080
MAX_BUFFER_SIZE = 1024

def main():
    server_socket = socket.socket()
    server_socket.bind(('0.0.0.0', PORT))
    server_socket.listen(1)

    print("Server listening on port", PORT)
    
    client_socket, client_address = server_socket.accept()
    print("Accepted connection from", client_address)
    
    data = client_socket.recv(MAX_BUFFER_SIZE).decode('utf-8')
    print("Received message from client:", data)
    
    client_socket.close()
    server_socket.close()

if __name__ == "__main__":
    main()
