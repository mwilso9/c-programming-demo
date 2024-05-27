#include "jumpChallenge.h"

static void challenge1();

jmp_buf challengebuf;
#define MAX_RUNS 5

int jumpChallengeFunc() {
    challenge1();
    return 0;
}

void challenge1() {
    int count = 0;
    
    while(1) {
        if(setjmp(challengebuf)) {
            break;
        }
        count++;
        //dummy code
        printf("Running code for ");
        if(count < 10 || count > 20) {
            if(count % 10 == 1)
                printf("%dst",count);
            else if(count % 10 == 2)
                printf("%dnd",count);
            else if(count % 10 == 3)
                printf("%drd",count);
            else
                printf("%dth",count);
        }
        else
            printf("%dth",count);
        printf(" time\n");
        if(count >= MAX_RUNS)
            error_recovery();
    }
    return;
}

void error_recovery()
{
    printf("Error occurred\n");
    longjmp(challengebuf,1);
}