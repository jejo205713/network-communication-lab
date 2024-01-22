# udp_client.py
import socket

SERVER_ADDRESS = '127.0.0.1'
SERVER_PORT = 8080

def main():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    message = input("Enter your message: ")
    client_socket.sendto(message.encode('utf-8'), (SERVER_ADDRESS, SERVER_PORT))

    print(f"Message sent to the server: {message}")

if __name__ == "__main__":
    main()
