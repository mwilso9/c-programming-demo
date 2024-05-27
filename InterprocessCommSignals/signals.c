#include "signals.h"
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <string.h>

/* interprocess communication other than signals:
 *    pipes, named pipes, message queues, shared memory, sockets
 */

static void class1();
static void class2();
static void class3();
static void class4();
static void class5();
static void class6();
static void class7();

typedef void (*signalhandler_t)(int);
typedef struct sigaction sigaction_t;

void handler_dividebyzero(int);
void signalHandler(int);
void termination_handler(int);
static void hdl(int, siginfo_t*, void*);

int signalsClass() {
    class1();
    class2();
    class3();
    class4();
    class5();
    class6();
    class7();
    return 0;
}

void class1() {
    int mypid, myppid;
    printf("Program to know PID and PPID's info\n");
    mypid = getpid();
    myppid = getppid();
    printf("My process ID is %d\n",mypid);
    printf("My parent process ID is %d\n",myppid);
    printf("Corss verification of pid's by executing process commands on shell\n");
    system("ps -ef");
    return;
}

void class2() {
    printf("Testing SIGSTOP\n");
    raise(SIGSTOP);
    printf("I am back\n\n");
    return;
}

void class3() {
    alarm(5);
    //NEED TO CATCH SIGALARM or process terminates
    //  signal(SIGALARM,alarmHandler);
    for(int i = 1; i < 10; i++) {
        printf("%d\n",i);
        sleep(1);
    }
    return;
}

void class4() {
    int v1 = 121, v2 = 0, result = 0;
    signalhandler_t sigHandlerReturn;
    
    sigHandlerReturn = signal(SIGFPE,handler_dividebyzero);
    
    if(sigHandlerReturn == SIG_ERR) {
        perror("Signal Error: ");
        return;
    }
    result = v1/v2;
    printf("Result of Divide by Zero is %d\n",result);
    
    return;
}

void handler_dividebyzero(int signum) {
    if(signum == SIGFPE) {
        printf("Received SIGFPE, Divide by Zero Exception\n");
        exit(0);
    }
    else {
        printf("Received %d Signal\n",signum);
        return;
    }
}

void class5() {
    int i; //counter used to loop 100 times
    int x; //variable to hold random values between 1-50
    
    signal(SIGINT,signalHandler); // register signal handler
//    signal(SIGINT,SIG_IGN);
    srand(clock());
    
    //output numbers 1 to 100
    for(i = 1; i <= 999; i++) {
        x = 1 + rand() % 50;
        if(x == 25) {
            raise(SIGINT);
        }
    
        printf("%4d",i);
    
        if(i%10 == 0) {
            printf("\n");
        }
    }
    return;
}

void signalHandler(int signalValue) {
    int response; //user's response to signal (1 or 2)
    printf("%s%d%s\n%s","\nInterrupt signal ( ", signalValue, " ) received.","Do you wish to continue ( 1 = yes or 2 = no )? ");
    scanf("%d",&response);
    
    //check for invalid responses
    while(response != 1 && response != 2) {
        printf("( 1 = yes or 2 = no )? ");
        scanf("%d",&response);
    }
    
    //determine if time to exit
    if(response == 1) {
        //reregister signal handler for next SIGINT
        signal(SIGINT,signalHandler);
    }
    else {
        exit(EXIT_SUCCESS);
    }
}

/* struct sigation contains members:
 *   sa_handler -- void * function with int parameter
 *   sa_sigaction -- void * function with int, siginfo_t*, and void* paremeters
 *   sa_mask -- mask of signals that should be blocked during execution
 *   sa_flags -- set of flags which modify behavior of signal
 *   sa_restorer -- void * function with no parameters, returns 0 on success and -1 on failure
 */
 
//handler only takes one int as parameter, because we are using sa_handler
void termination_handler(int signum) {
/*    struct temp_file *p;
    
    for(p = temp_file_list; p; p = p->next;
        unlink(p->name);
*/}

void class6() {
    sigaction_t new_action, old_action;

    //set up the struct to specifiy the new action.
    new_action.sa_handler = termination_handler;
    sigemptyset(&new_action.sa_mask);
    new_action.sa_flags = 0;
    
    sigaction (SIGINT, NULL, &old_action);
    if(old_action.sa_handler != SIG_IGN)
        sigaction (SIGINT, &new_action, NULL);
        
    sigaction(SIGHUP, NULL, &old_action);
    if(old_action.sa_handler != SIG_IGN)
        sigaction(SIGHUP, &new_action, NULL);
        
    sigaction(SIGTERM, NULL, &old_action);
    if(old_action.sa_handler != SIG_IGN)
        sigaction(SIGTERM, &new_action, NULL);
    
    return;
}


//handler takes three parameters because we are using sa_sigaction
void hdl(int sig, siginfo_t *siginfo, void *context) {
    printf("Sending PID: %ld, UID: %ld\n", (long)siginfo->si_pid, (long)siginfo->si_uid);
}

void class7() {
    sigaction_t act;
    memset(&act, '\0', sizeof(act));
    
    // Use the sa sigaction field because the handles has two additional parameters
    //     hld contains a signinfo_t and a void pointer, see the function prototype
    act.sa_sigaction = &hdl;
    
    //the SA_SIGINFO flag tells sigaction() to use the sa_sigaction field, not sa_handler
    act.sa_flags = SA_SIGINFO;
    
    if(sigaction(SIGINT, &act, NULL) < 0) {
        perror("sigaction");
        return;
    }
    
    while(1)
        sleep(3);
    
    return;
}