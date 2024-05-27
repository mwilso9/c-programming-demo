#include "usefulLibChallenge.h"
#include <time.h>

static void challenge1();
static void challenge2();
static void challenge3();
static void challenge4();

void fillarray(double[], const int);
void displayarray(const double[], const int);
int compdbl(const void *, const void *);

int usefulLibChallenge() {
    printf("------Challenge #1-----\n");
    challenge1();
    printf("\n\n------Challenge #2-----\n");
    challenge2();
    printf("\n\n------Challenge #3-----\n");
    challenge3();
    printf("\n------Challenge #4-----\n");
    challenge4();
    return 0;
}
#define SIZE 50
void challenge1() {
    double numbers[SIZE] = {0};

    fillarray(numbers,SIZE);
    
    printf("Number of data = %d\n",SIZE);
    displayarray(numbers,SIZE);
    
    return;
}

void challenge2() {
    double numbers[SIZE] = {0};

    fillarray(numbers,SIZE);
    printf("Unsorted list\n");
    displayarray(numbers,SIZE);
    
    qsort(numbers,SIZE,sizeof(double),compdbl);
    
    printf("\nSorted list\n");
    displayarray(numbers,SIZE);
    
    return;
}

void fillarray(double ar[], const int n) {
    srand(time(0));
    for(int i = 0; i < n; i++) {
        ar[i] = (((double)(rand() % 1000))/1000) - 0.5;
    }
}

void displayarray(const double ar[], const int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        printf("%.3lf",ar[i]);
        if(count == n/5) {
            printf("\n");
            count = 0;
        }
        else {
            printf("\t");
            count++;
        }
    }
}

int compdbl(const void *d1, const void *d2) {
    double diff = *(double *)d1 - *(double *)d2;
    if(diff > 0) 
        return 1;
    else if(diff < 0)
        return -1;
    else
        return 0;
}

void challenge3() {
    time_t current = time(NULL);
    char *cur_str;
    if(current == ((time_t)-1)) {
        fprintf(stderr,"Failure obtaining current time\n");
        exit(EXIT_FAILURE);
    }
    cur_str = ctime(&current);
    if(cur_str == NULL) {
        fprintf(stderr,"Operation failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Current time   (ctime) is: %s\n",cur_str);
    
    struct tm *local = localtime(&current);
    if(local == NULL) {
        fprintf(stderr,"Failed to convert time_t to local tm");
        exit(EXIT_FAILURE);
    }
    if(mktime(local) == -1) {
        fprintf(stderr,"Operation failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Current time (asctime) is: %s",asctime(local));
    
    return;
}

void challenge4() {
    time_t current = time(NULL);
    if(current == ((time_t)-1)) {
        fprintf(stderr,"Failure obtaining current time\n");
        exit(EXIT_FAILURE);
    }
    time_t monBegt = 0;
    long long int diff = 0;
    struct tm monBegtm;
    struct tm *local = localtime(&current);
    if(local == NULL) {
        fprintf(stderr,"Failed to convert time_t to local tm\n");
        exit(EXIT_FAILURE);
    }

    monBegtm.tm_sec = 0;
    monBegtm.tm_min = 0;
    monBegtm.tm_hour = 0;
    monBegtm.tm_mday = 1;
    monBegtm.tm_mon = local->tm_mon;
    monBegtm.tm_year = local->tm_year;
    
    if((monBegt = mktime(&monBegtm)) == -1) {
        fprintf(stderr,"Operation failed.\n");
        exit(EXIT_FAILURE);
    }

    diff = (long long int) difftime(current,monBegt);
    printf("%lld seconds have passed since the beginning of the month.\n",diff);
    
    printf("%lld days %lld hours %lld minutes %lld seconds have passed since the beginning of the month.\n",
            (diff/(60*60*24)),(diff/(60*60))%24,(diff/60)%60,diff%60);
}