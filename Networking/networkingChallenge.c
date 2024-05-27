#include "networkingChallenge.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>

#define DEBUG

static int challengeServer();
short socketCreateServerChallenge();
int bindCreatedSocketChallenge(int);
#define PORT 12345
#define MAX_CLIENT_CNT 2

static int challengeClient1();
short socketCreateClientChallenge(int);
int socketConnectClientChallenge(int);
int socketSendClientChallenge(int, int*, short, int);
int socketReceiveChallenge(int, int*, short, int);

static int challengeClient2();

int networkingChallenge() {
    //doing forks to avoid multiple program executables
    pid_t pid;
    
    pid = fork();
    if(pid == 0) {
        pid = fork();
        if(pid == 0) {
            //parent creates server socket
            challengeServer();
        }
        else {
            //second child creates client 2 socket
            sleep(1); //sleeping to ensure client 1 is connected before client 2
            challengeClient2();
        }
    }
    else {
        //first child creates client 1 socket
        challengeClient1();

    }
    return 0;
}


short socketCreateServerChallenge() {
    short hSocket;
    #ifdef DEBUG
        printf("Server -- Create the socket\n");
    #endif
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int bindCreatedSocketChallenge(int hSocket) {
    int iRetval = -1;
    int clientPort = PORT;
    
    struct sockaddr_in remote = {0};
    
    //Internet address family
    remote.sin_family = AF_INET;
    
    //Any incoming interface
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(clientPort); //local port
    
    iRetval = bind(hSocket, (struct sockaddr *) &remote, sizeof(remote));
    return iRetval;
}

static int challengeServer() {
    int socket_desc = 0, sock = 0, clientLen = 0;
    struct sockaddr_in client;
    int client_message = 0;
    int message = 0;
    //const char *pMessage = "hello from client";
    int clientCnt = 0;
    
    //create socket
    socket_desc = socketCreateServerChallenge();
    if(socket_desc == -1) {
        #ifdef DEBUG
            printf("Server -- Could not create socket");
        #endif
        return 1;
    }
    #ifdef DEBUG
        printf("Server -- Socket created\n");
    #endif
    
    //bind
    if(bindCreatedSocketChallenge(socket_desc) < 0) {
        //print error message
        #ifdef DEBUG
            perror("Server -- bind failed.");
        #endif
        return 1;
    }
    #ifdef DEBUG
        printf("Server -- bind done\n");
    #endif
    
    //listen
    listen(socket_desc, MAX_CLIENT_CNT);
    
    //accept any incoming connection
    while(1) {
        #ifdef DEBUG
            printf("Server -- Waiting for incoming connections...\n");
        #endif
        clientLen = sizeof(struct sockaddr_in);
        
        //accept connection from incoming client
        sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&clientLen);
        if(sock < 0) {
            #ifdef DEBUG
                perror("Server -- accept failed");
            #endif
            return 1;
        }
        #ifdef DEBUG
            printf("Server -- Connection accepted\n");
        #endif
        
        /*different action based on client order
         * receives int value from first client.
         * decrements received value.
         * sends decremented value to second client.
         */
        clientCnt++;
        if(clientCnt == 1) {
            //receive reply from client
            if(recv(sock, &client_message, sizeof(int), 0) < 0) {
                #ifdef DEBUG
                    printf("Server -- recv failed");
                #endif
                break;
            }
            
            printf("Server received : %d\n", client_message);
            message = client_message - 1;
            printf("Server sending : %d\n", message);

        }
        else {
            //send data
            if(send(sock, &message, sizeof(int), 0) < 0) {
                #ifdef DEBUG
                    printf("Server -- Send failed");
                #endif
                return 1;
            }
        }
        close(sock);
        
        if(clientCnt >= MAX_CLIENT_CNT) break;
        
        sleep(1);
    }
    return 0;    
}

static int challengeClient1() {
    int hSocket = 0;
    int sendToServer = 10;
    
    //create socket
    hSocket = socketCreateClientChallenge(1);
    if(hSocket == -1) {
        #ifdef DEBUG
            printf("Client 1 -- Could not create socket\n");
        #endif
        return 1;
    }
    #ifdef DEBUG
        printf("Client 1 -- Socket is created\n");
    #endif
    
    //connect to remote server
    if(socketConnectClientChallenge(hSocket) < 0) {
        #ifdef DEBUG
            perror("Client 1 -- connect failed.\n");
        #endif
        return 1;
    }
    #ifdef DEBUG
        printf("Client 1 -- Successfully connected with server\n");
    #endif
    
    //send data to server
    #ifdef DEBUG
        printf("Client 1 sending : %d\n", sendToServer);
    #endif
    socketSendClientChallenge(hSocket, &sendToServer, sizeof(int), 1);
    
    close(hSocket);
    
    return 0;    
}

static int challengeClient2() {
    int hSocket = 0;
    int server_reply = 0;
    
    //create socket
    hSocket = socketCreateClientChallenge(2);
    if(hSocket == -1) {
        #ifdef DEBUG
            printf("Client 2 -- Could not create socket\n");
        #endif
        return 1;
    }
    #ifdef DEBUG
        printf("Client 2 -- Socket is created\n");
    #endif
    
    //connect to remote server
    if(socketConnectClientChallenge(hSocket) < 0) {
        #ifdef DEBUG
            perror("Client 2 -- connect failed.\n");
        #endif
        return 1;
    }
    #ifdef DEBUG
        printf("Client 2 -- Successfully connected with server\n");
    #endif
    
    //receive data from server
    socketReceiveChallenge(hSocket, &server_reply, sizeof(int), 2);
    printf("Client 2 received : %d\n\n", server_reply);
    
    close(hSocket);
    
    return 0;    
}

short socketCreateClientChallenge(int clientID) {
    short hSocket;
    #ifdef DEBUG
        printf("Client %d -- Create the socket\n", clientID);
    #endif
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int socketConnectClientChallenge(int hSocket) {
    int iRetval = -1;
    int ServerPort = PORT;
    
    struct sockaddr_in remote = {0};
    remote.sin_addr.s_addr = inet_addr("127.0.0.1"); //local host address
    remote.sin_family = AF_INET;
    remote.sin_port = htons(ServerPort);
    
    iRetval = connect(hSocket, (struct sockaddr *)&remote, sizeof(remote));
    return iRetval;
}

//send data to server and set timeout of 20 sec
int socketSendClientChallenge(int hSocket, int *Rqst, short lenRqst, int clientID) {
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20; //20 sec timeout
    tv.tv_usec = 0;
    
    if(setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char *) &tv, sizeof(tv)) < 0) {
        #ifdef DEBUG
            printf("Client %d -- Time Out\n", clientID);
        #endif
        return -1;
    }
    
    shortRetval = send(hSocket, Rqst, lenRqst, 0);
    return shortRetval;
}

//receive data from server
int socketReceiveChallenge(int hSocket, int *Rsp, short RcvSize, int clientID) {
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20; //20 sec timeout
    tv.tv_usec = 0;
    
    if(setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char *) &tv, sizeof(tv)) < 0) {
        #ifdef DEBUG
            printf("Client %d -- Time Out\n", clientID);
        #endif
        return -1;
    }
    
    shortRetval = recv(hSocket, Rsp, RcvSize, 0);
    #ifdef DEBUG
        printf("Client %d -- Response %d\n", clientID, *Rsp);
    #endif
    return shortRetval;
}