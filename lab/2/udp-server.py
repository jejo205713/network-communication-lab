# udp_server.py
import socket

PORT = 8080
MAX_BUFFER_SIZE = 1024

def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.bind(('0.0.0.0', PORT))

    print(f"UDP Server is listening on port {PORT}...")

    while True:
        data, client_address = server_socket.recvfrom(MAX_BUFFER_SIZE)
        print(f"Message from client at {client_address}: {data.decode('utf-8')}")

if __name__ == "__main__":
    main()
