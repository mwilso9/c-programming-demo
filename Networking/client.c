#include "client.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>

static int class1();

short socketCreateClient();
int socketConnect(int);
int socketSend(int, char*, short);
int socketReceive(int, char*, short);
#define CLIENT_MSG_BUF_SIZE 200
#define SERVER_MSG_BUF_SIZE 100

int clientClass() {
    class1();
    return 0;
}

short socketCreateClient() {
    short hSocket;
    printf("Client -- Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int socketConnect(int hSocket) {
    int iRetval = -1;
    int ServerPort = 12345;
    
    struct sockaddr_in remote = {0};
    remote.sin_addr.s_addr = inet_addr("127.0.0.1"); //local host address
    remote.sin_family = AF_INET;
    remote.sin_port = htons(ServerPort);
    
    iRetval = connect(hSocket, (struct sockaddr *)&remote, sizeof(remote));
    return iRetval;
}

//send data to server and set timeout of 20 sec
int socketSend(int hSocket, char *Rqst, short lenRqst) {
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20; //20 sec timeout
    tv.tv_usec = 0;
    
    if(setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char *) &tv, sizeof(tv)) < 0) {
        printf("Client -- Time Out\n");
        return -1;
    }
    
    shortRetval = send(hSocket, Rqst, lenRqst, 0);
    return shortRetval;
}

//receive data from server
int socketReceive(int hSocket, char *Rsp, short RcvSize) {
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20; //20 sec timeout
    tv.tv_usec = 0;
    
    if(setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char *) &tv, sizeof(tv)) < 0) {
        printf("Client -- Time Out\n");
        return -1;
    }
    
    shortRetval = recv(hSocket, Rsp, RcvSize, 0);
    printf("Client -- Response %s\n", Rsp);
    return shortRetval;
}

int class1() {
    int hSocket = 0, read_size = 0;
    struct sockaddr_in server;
    char sendToServer[SERVER_MSG_BUF_SIZE] = {0};
    char server_reply[CLIENT_MSG_BUF_SIZE] = {0};
    
    //create socket
    hSocket = socketCreateClient();
    if(hSocket == -1) {
        printf("Client -- Could not create socket\n");
        return 1;
    }
    printf("Client -- Socket is created\n");
    
    //connect to remote server
    if(socketConnect(hSocket) < 0) {
        perror("Client -- connect failed.\n");
        return 1;
    }
    printf("Client -- Successfully connected with server\n");
    //printf("Enter the Message: ");
    //fgets(sendToServer, SERVER_MSG_BUF_SIZE, stdin);
    strcpy(sendToServer, "hello from client");
    
    //send data to server
    socketSend(hSocket, sendToServer, strlen(sendToServer));
    
    //receive data from server
    read_size = socketReceive(hSocket, server_reply, CLIENT_MSG_BUF_SIZE);
    printf("Client -- Server Response : %s\n\n", server_reply);
    
    close(hSocket);
    
    return 0;
}