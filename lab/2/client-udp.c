// udp_client.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080
#define SERVER_IP "127.0.0.1"
#define MAX_BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    // Filling server information
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Enter message to send to the server (Type 'exit' to quit): ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);

        // Exit loop if the user types 'exit'
        if (strncmp(buffer, "exit", 4) == 0)
            break;

        sendto(sockfd, (const char*)buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr*)&server_addr, sizeof(server_addr));
        printf("Message sent to server.\n");
    }

    close(sockfd);
    return 0;
}

