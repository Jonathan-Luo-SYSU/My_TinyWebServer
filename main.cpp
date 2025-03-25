// #include <iostream>
// #include <cstring>
// #include <unistd.h>
// #include <arpa/inet.h>

// #define PORT 8080
// #define BUFFER_SIZE 1024
#include "webserver.h"
int main() {

    WebServer webServer;
    webServer.event_process();
    // int server_fd, new_socket;
    // struct sockaddr_in address;
    // int addrlen = sizeof(address);
    // char buffer[BUFFER_SIZE] = {0};
    // const char* hello = "Hello from server";

    // // Creating socket file descriptor
    // if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    //     perror("socket failed");
    //     exit(EXIT_FAILURE);
    // }

    // // Setting up the address struct
    // address.sin_family = AF_INET;
    // address.sin_addr.s_addr = INADDR_ANY;
    // address.sin_port = htons(PORT);

    // // Binding the socket to the port
    // if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    //     perror("bind failed");
    //     close(server_fd);
    //     exit(EXIT_FAILURE);
    // }

    // // Listening for incoming connections
    // if (listen(server_fd, 3) < 0) {
    //     perror("listen");
    //     close(server_fd);
    //     exit(EXIT_FAILURE);
    // }

    // std::cout << "Server is listening on port " << PORT << std::endl;

    // while (true) {
    //     // Accepting a new connection
    //     if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
    //         perror("accept");
    //         close(server_fd);
    //         exit(EXIT_FAILURE);
    //     }

    //     std::cout << "New connection, socket fd is " << new_socket << ", ip is : " << inet_ntoa(address.sin_addr) << ", port : " << ntohs(address.sin_port) << std::endl;

    //     // Reading data from the client
    //     int valread = read(new_socket, buffer, BUFFER_SIZE);
    //     std::cout << "Received: " << buffer << std::endl;

    //     // Converting received data to uppercase
    //     for (int i = 0; i < valread; i++) {
    //         if (buffer[i] >= 'a' && buffer[i] <= 'z') {
    //             buffer[i] = buffer[i] - 'a' + 'A';
    //         }
    //     }

    //     // Sending the converted data back to the client
    //     send(new_socket, buffer, valread, 0);
    //     std::cout << "Sent: " << buffer << std::endl;

    //     // Closing the current connection
    //     close(new_socket);
    // }

    // // Closing the server socket
    // close(server_fd);
    return 0;
}