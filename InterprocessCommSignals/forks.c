#include "forks.h"
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define MAX_COUNT   500
#define BUF_SIZE    100

static void class1();
static void class2();
static void class3();

void childProcess();
void parentProcess();

int forksClass() {
    class1();
    class2();
    class3();
    return 0;
}

void class1() {
    fork();
    printf("Hello world!\n");
    return;
}

void class2() {
    pid_t   pid;
    char    buf[BUF_SIZE];
    
    fork();
    pid = getpid();
    for(int i = 1; i <= MAX_COUNT; i++) {
        sprintf(buf,"This line is from pid %d, value = %d\n",pid,i);
        write(1,buf,strlen(buf));
    }
}

void childProcess() {
    int i = 0;
    for(i = 1; i <= MAX_COUNT; i++)
        printf("\tThis line is from child, value = %d\n", i);
    
    printf("\t*** Child process is done ***\n");
}

void parentProcess() {
    int i = 0;
    for(i = 1; i <= MAX_COUNT; i++)
        printf("This line is from parent, value = %d\n", i);
    
    printf("*** Parent is done ***\n");
}

void class3() {
    pid_t pid;
    
    pid = fork();
    
    if(pid == 0)
        childProcess();
    else if(pid > 0)
        parentProcess();
    else { //fork failed
        printf("fork() failed\n");
        return;
    }
}