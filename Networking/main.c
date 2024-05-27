#include "server.h"
#include "client.h"
#include "networkingChallenge.h"
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
/*    pid_t pid;
    
    pid = fork();
    if(pid == 0) {
        //creating server socket
        serverClass();
    }
    else {
        //creating client socket
        clientClass();
        return 0;
    }
*/
    //challenge
    networkingChallenge();
    
	return 0;
}