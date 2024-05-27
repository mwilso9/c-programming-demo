#include "mutexes.h"
#include <pthread.h>
#include <unistd.h>

#define NTHREADS 10

static void class1();
static void class2();
static void class3();

void *do_process();
void *thread_function(void *);
void *resource1();
void *resource2();

pthread_mutex_t lock = NULL;
int j = 0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;
pthread_mutex_t lock1 = NULL;
pthread_mutex_t lock2 = NULL;

int mutexesClass() {
    class1();
    class2();
    class3();
    return 0;
}

void *do_process() {
    pthread_mutex_lock(&lock);
    int i = 0;
    j++;
    
    while(i<5) {
        printf("%d", j);
        sleep(1);
        i++;
    }
    printf("...Done\n");
    pthread_mutex_unlock(&lock);
    
    return NULL;
}

void class1() {
    //int err = 0;
    pthread_t t1, t2;
    
    if(pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex initialization failed.\n");
        return;
    }
    
    j = 0;
    
    pthread_create(&t1, NULL, do_process, NULL);
    pthread_create(&t2, NULL, do_process, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_exit(NULL);
    
    return;
}

void *thread_function(void *dummyPtr) {
    printf("Thread number %ld\n", (long int) pthread_self());
    pthread_mutex_lock(&mutex1);
    counter++;
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

void class2() {
    pthread_t thread_id[NTHREADS];
    int i = 0, j = 0;
    
    for(i = 0; i < NTHREADS; i++) {
        pthread_create(&thread_id[i], NULL, thread_function, NULL);
    }
    
    for(j = 0; j < NTHREADS; j++) {
        pthread_join(thread_id[j], NULL);
    }
    
    //note that all threads are complete, can print final results.
    //without the join, could be printing a value for all threads end.
    printf("Final counter value: %d\n", counter);
    return;
}

void *resource1() {
    pthread_mutex_lock(&lock1);
    
    printf("Job started in resource1...\n");
    sleep(2);
    
    printf("Trying to get resource2\n");
    while (pthread_mutex_trylock(&lock2)) {
        pthread_mutex_unlock(&lock1);
        sleep(2);
        pthread_mutex_lock(&lock1);
    }
    
    printf("Acquired resource2\n");
    pthread_mutex_unlock(&lock2);
    
    sleep(2);
    
    printf("Job finished in resource1...\n");
    pthread_mutex_unlock(&lock1);
    
    pthread_exit(NULL);

    return NULL;
}

void *resource2() {
    pthread_mutex_lock(&lock2);
    
    printf("Job started in resource2...\n");
    sleep(2);
    
    printf("Trying to get resource1\n");
    pthread_mutex_lock(&lock1);
    printf("Acquired resource1\n");
    pthread_mutex_unlock(&lock1);
    
    printf("Job finished in resource2...\n");
    pthread_mutex_unlock(&lock2);
    
    pthread_exit(NULL);
    
    return NULL;
}

void class3() {
    pthread_mutex_init(&lock1,NULL);
    pthread_mutex_init(&lock2,NULL);
    
    pthread_t t1, t2;
    
    pthread_create(&t1, NULL, resource1, NULL);
    pthread_create(&t2, NULL, resource2, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    return;
}