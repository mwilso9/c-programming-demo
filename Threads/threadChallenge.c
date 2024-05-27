#include "threadChallenge.h"
#include <pthread.h>
#include <string.h>
#include <unistd.h>

static void challenge1();
void *message_function(void *);
#define NUM_THREADS 10
int counterChallenge = 0;

static void challenge2();
void *locking_message_function(void *);
pthread_mutex_t counter_lock = PTHREAD_MUTEX_INITIALIZER;

static void challenge3();
void *cond_lock_message_function(void *);
int num_evens_finished = 0;
#define EVEN_THREAD_COUNT ((NUM_THREADS/2) + (NUM_THREADS%2))
pthread_mutex_t challenge_cond_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  challenge_cond  = PTHREAD_COND_INITIALIZER;

int threadChallenge() {
    printf("\tChallenge 1...\n");
    challenge1();                   //Challenge 1: print two messages and increment global counter. observe inconsistencies
    printf("\n\tChallenge 2...\n");
    counterChallenge = 0;
    challenge2();                   //Challenge 2: same as #1 but must print both messages together
    printf("\n\tChallenge 3...\n");
    counterChallenge = 0;
    challenge3();                   //Challenge 3: same as #2 but must print all even threads before odd threads
    
    pthread_exit(NULL);
    
    return 0;
}

/*--------------------------Challenge 1--------------------------*/
void *message_function(void *ptr) {
    int message;
    message = *(int *)ptr;

    counterChallenge++;

    printf("Message: %d\tThread ID: %ld\tModified Counter to: %2d\n",message, (long int) pthread_self(), counterChallenge);
    printf("Message: %d\tThread ID: %ld\t    Read Counter as: %2d\n",message, (long int) pthread_self(), counterChallenge);

    return NULL;
}

void challenge1() {
    pthread_t thread_id[NUM_THREADS];
    int str[NUM_THREADS] = {0};
    int i = 0, j = 0;
    
    for(i = 0; i < NUM_THREADS; i++) {
        str[i] = i;
        pthread_create(&thread_id[i], NULL, message_function, (void *)&(str[i]));
    }
    
    for(j = 0; j < NUM_THREADS; j++) {
        pthread_join(thread_id[j], NULL);
    }

    //pthread_exit(NULL);
    
    return;
}

/*--------------------------Challenge 2--------------------------*/
void *locking_message_function(void *ptr) {
    int message;
    message = *(int *)ptr;

    pthread_mutex_lock(&counter_lock);
    counterChallenge++;

    printf("Message: %d\tThread ID: %ld\tModified Counter to: %2d\n",message, (long int) pthread_self(), counterChallenge);
    printf("Message: %d\tThread ID: %ld\t    Read Counter as: %2d\n",message, (long int) pthread_self(), counterChallenge);

    pthread_mutex_unlock(&counter_lock);
    return NULL;
}

void challenge2() {
    pthread_t thread_id[NUM_THREADS];
    int str[NUM_THREADS] = {0};

    int i = 0, j = 0;
    
    for(i = 0; i < NUM_THREADS; i++) {
        str[i] = i;
        pthread_create(&thread_id[i], NULL, locking_message_function, (void *)&(str[i]));
    }
    
    for(j = 0; j < NUM_THREADS; j++) {
        pthread_join(thread_id[j], NULL);
    }

    //pthread_exit(NULL);
    
    return;
}
/*--------------------------Challenge 3--------------------------*/
void *cond_lock_message_function(void *ptr) {
    int message;
    message = *(int *)ptr;

    pthread_mutex_lock(&challenge_cond_lock);
    if(message % 2 != 0) {
        while(num_evens_finished < EVEN_THREAD_COUNT) {
            pthread_cond_wait(&challenge_cond, &challenge_cond_lock);
        }
    }
    else { //used in lecture demo
        num_evens_finished++;
    }

    pthread_mutex_lock(&counter_lock);
    counterChallenge++;

    printf("Message: %d\tThread ID: %ld\tModified Counter to: %2d\n",message, (long int) pthread_self(), counterChallenge);
    printf("Message: %d\tThread ID: %ld\t    Read Counter as: %2d\n",message, (long int) pthread_self(), counterChallenge);

    pthread_mutex_unlock(&counter_lock);

//  removed since should not broadcast from created threads to avoid race condition if all even threads finish before all odd threads lock
/*
    if(message % 2 == 0) {
        num_evens_finished++;
        printf("Even finished: %d out of %d\n",num_evens_finished,EVEN_THREAD_COUNT);
        if(num_evens_finished >= EVEN_THREAD_COUNT) {
            pthread_cond_broadcast(&challenge_cond);
        }
    }
*/    pthread_mutex_unlock(&challenge_cond_lock);

    return NULL;
}

void challenge3() {
    pthread_t thread_id[NUM_THREADS];
    int str[NUM_THREADS] = {0};

    int i = 0, j = 0;
    
    for(i = 0; i < NUM_THREADS; i++) {
        str[i] = i;
        pthread_create(&thread_id[i], NULL, cond_lock_message_function, (void *)&(str[i]));
    }
    
    //used in lecture demo {
    sleep(1);
    while(num_evens_finished < EVEN_THREAD_COUNT);
    pthread_cond_broadcast(&challenge_cond);
    // }
    
    for(j = 0; j < NUM_THREADS; j++) {
        pthread_join(thread_id[j], NULL);
    }

    //pthread_exit(NULL);

    return;
}