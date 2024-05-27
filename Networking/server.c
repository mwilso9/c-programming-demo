#include "server.h"
//#include <sys/types.h>
#include <sys/socket.h>
//#include <netinet/in.h>
//#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

static int class1();

short socketCreateServer();
int bindCreatedSocket(int);
#define CLIENT_MSG_BUF_SIZE 200
#define SERVER_MSG_BUF_SIZE 100

int serverClass() {
    class1();
    return 0;
}

short socketCreateServer() {
    short hSocket;
    printf("Server -- Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int bindCreatedSocket(int hSocket) {
    int iRetval = -1;
    int clientPort = 12345;
    
    struct sockaddr_in remote = {0};
    
    //Internet address family
    remote.sin_family = AF_INET;
    
    //Any incoming interface
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(clientPort); //local port
    
    iRetval = bind(hSocket, (struct sockaddr *) &remote, sizeof(remote));
    return iRetval;
}

int class1() {
    int socket_desc = 0, sock = 0, clientLen = 0;
    struct sockaddr_in client;
    char client_message[CLIENT_MSG_BUF_SIZE] = {0};
    char message[SERVER_MSG_BUF_SIZE] = {0};
    const char *pMessage = "hello from client";
    
    //create socket
    socket_desc = socketCreateServer();
    if(socket_desc == -1) {
        printf("Server -- Could not create socket");
        return 1;
    }
    printf("Server -- Socket created\n");
    
    //bind
    if(bindCreatedSocket(socket_desc) < 0) {
        //print error message
        perror("Server -- bind failed.");
        return 1;
    }
    printf("Server -- bind done\n");
    
    //listen
    listen(socket_desc, 3);
    
    //accept any incoming connection
//    while(1) {
        printf("Server -- Waiting for incoming connections...\n");
        clientLen = sizeof(struct sockaddr_in);
        
        //accept connection from incoming client
        sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&clientLen);
        if(sock < 0) {
            perror("Server -- accept failed");
            return 1;
        }
        printf("Server -- Connection accepted\n");
        memset(client_message, '\0', sizeof client_message);
        memset(message, '\0', sizeof message);
        
        //receive reply from client
        if(recv(sock, client_message, CLIENT_MSG_BUF_SIZE, 0) < 0) {
            printf("Server -- recv failed");
//            break;
        }
        printf("Server -- Client reply : %s\n", client_message);
        
        if(strcmp(pMessage, client_message) == 0) {
            strcpy(message, "Hi there !");
        }
        else {
            strcpy(message, "Invalid Message !");
        }
        
        //send data
        if(send(sock, message, strlen(message), 0) < 0) {
            printf("Server -- Send failed");
            return 1;
        }
        close(sock);
        
        sleep(1);
//    }
    return 0;
}