#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#define PORT 8080
#define MAX_BUFFER_SIZE 1024
int main() {
int client_fd;
struct sockaddr_in server_address;
char message[MAX_BUFFER_SIZE];

// Create a socket
if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
perror("Socket creation failed");
exit(EXIT_FAILURE);
}
// Configure server address
server_address.sin_family = AF_INET;
server_address.sin_port = htons(PORT);
if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
perror("Invalid address/ Address not supported");
exit(EXIT_FAILURE);
}
// Connect to the server using TCP
if (connect(client_fd, (struct sockaddr *)&server_address,
sizeof(server_address)) < 0) {
perror("Connection Failed");
exit(EXIT_FAILURE);
}
// Get user input for the message
printf("Enter a message to send to the server: ");
fgets(message, MAX_BUFFER_SIZE, stdin);
// Send the message to the server using TCP
send(client_fd, message, strlen(message), 0);
// Close the connection
close(client_fd);
return 0;
}
