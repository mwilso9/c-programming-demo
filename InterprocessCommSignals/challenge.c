#include "signalsChallenge.h"
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

#define MAX_NAME_LEN 13
#define MAX_BUF_SIZE 100

static void challenge1();
static void challenge2();

void end_game();
void error(char*);

void alarm_handler(int);
void interrupt_handler(int);

typedef void (*signalhandler_t)(int);
typedef struct sigaction sigaction_t;

int score = 0;

int signalsChallenge() {
    challenge1();
    challenge2();
    return 0;
}

void challenge1() {
    sigaction_t new_action, old_action;
    
    srand (time(0));
   
    //set SIGALARM intercept
    if(signal(SIGALRM, alarm_handler) == SIG_ERR) {
        fprintf(stderr, "Alarm signal function error.");
        return;
    }

    //set CTRL+C intercept
    new_action.sa_handler = interrupt_handler;
    sigemptyset(&new_action.sa_mask);
    new_action.sa_flags = 0;
    if(sigaction (SIGINT, &new_action, &old_action) < 0) {
        fprintf(stderr, "Interrupt signal function error.");
        return;        
    }
   
    while(1) {
        int a = rand() % 11;
        int b = rand() % 11;

        char txt[4];
    
        printf("\nWhat is %d times %d: ", a, b);
        //add 5 second timer
        alarm(5);
      
        fgets(txt, 4, stdin);

        int answer = atoi(txt);

        if(answer == a * b)
            score++;
        else
            printf("\nWrong! Score: %d\n", score);
    }

    return;
}

void end_game() {

   printf("\nFinal score: %d\n", score);
   exit(0); 
}

void error(char *msg)
{
   fprintf(stderr, "%s: %s\n", msg, strerror(errno));
   exit(1);
}

void alarm_handler(int signum) {
    printf("\nTIME'S UP!");
    raise(SIGINT);
}

void interrupt_handler(int signum) {
    end_game();
}


void challenge2() {
    pid_t id1 = 0, id2 = 0;
    char name[MAX_NAME_LEN] = {'\0'};
    char buf[MAX_BUF_SIZE] = {'\0'};
    
    id1 = fork();
    id2 = fork();
    if(id1 == 0) {
        if(id2 == 0) {
            sprintf(name, "third child");
        }
        else if(id2 > 0) {
            sprintf(name, "first child");
        }
        else {
            fprintf(stderr, "Failure to fork third child\n");
            exit(1);
        }
    }
    else if(id1 > 0) {
        if(id2 == 0) {
            sprintf(name, "second child");
        }
        else if(id2 > 0) {
            sprintf(name, "parent");
        }
        else {
            fprintf(stderr, "Failure to fork second child\n");
            exit(1);
        }
    }
    else {
        fprintf(stderr, "Failure to fork first child\n");
        exit(1);
    }
    
    //printf("%s\n%d %d\n\tmy id is %d\n\tmy parentid is %d\n\n",name,id1,id2,getpid(),getppid());
    sprintf(buf,"%s\n%d %d\n\tmy id is %d\n\tmy parentid is %d\n\n",name,id1,id2,getpid(),getppid());
    write(1,buf,strlen(buf));
    
    return;
}