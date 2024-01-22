# client.py
import socket

SERVER_ADDRESS = '127.0.0.1'
SERVER_PORT = 8080

def main():
    client_socket = socket.socket()
    client_socket.connect((SERVER_ADDRESS, SERVER_PORT))

    message = input("Enter your message: ")
    client_socket.send(message.encode('utf-8'))
    print("Message sent to server:", message)

    client_socket.close()

if __name__ == "__main__":
    main()
