// server.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#define PORT 8080
#define MAX_BUFFER_SIZE 1024
int main() {
int server_fd, new_socket, valread;
struct sockaddr_in address;
int addrlen = sizeof(address);
char buffer[MAX_BUFFER_SIZE] = {0};
// Create a socket
if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
perror("Socket creation failed");
exit(EXIT_FAILURE);
}
// Set up server address struct
address.sin_family = AF_INET;
address.sin_addr.s_addr = INADDR_ANY;
address.sin_port = htons(PORT);

// Bind the socket to the address
if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
perror("Bind failed");
exit(EXIT_FAILURE);
}
// Listen for incoming connections
if (listen(server_fd, 3) < 0) {
perror("Listen failed");
exit(EXIT_FAILURE);
}
// Accept incoming connection
if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
(socklen_t*)&addrlen)) < 0) {
perror("Accept failed");
exit(EXIT_FAILURE);
}
// Read data from the client using TCP
valread = read(new_socket, buffer, MAX_BUFFER_SIZE);
printf("Received message from client: %s\n", buffer);
// Close the connection
close(new_socket);
close(server_fd);
return 0;
}
