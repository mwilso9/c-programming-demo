#include "threadsIntro.h"
#include <pthread.h>
#include <string.h>
#include <malloc.h>

static void class1();
static void class2();
static void class3();
static void class4();

void *hello_fun();
void *print_message_function(void *);
void *printHello(void *);
void *hello_return(void *);

typedef struct thread_data {
    int     thread_id;
    int     sum;
    char    *message;
} thread_data_t;

int threadsIntroClass() {
    class1();
    class2();
    class3();
    class4();
    return 0;
}

void *hello_fun() {
    printf("Hello World\n");
    return NULL;
}

void class1() {
    pthread_t thread;
    pthread_create(&thread, NULL, hello_fun, NULL);
    pthread_join(thread,NULL);
    pthread_exit(NULL);
    return;
}

void *print_message_function(void *ptr) {
    char *message;
    message = (char *)ptr;
    printf("%s \n",message);
    return NULL;
}

void class2() {
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int iret1, iret2;
    
    //Create independent threads each of which will execute function
    iret1 = pthread_create(&thread1, NULL, print_message_function, (void *)message1);
    iret2 = pthread_create(&thread2, NULL, print_message_function, (void *)message2);
    //Wait till threads are complete before main continues.
    //Unless we wait, we run the risk of executing an exit which will terminate
    //the process and all threads before the threads have completed.
    
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    
    printf("Thread 1 returns: %d\n", iret1);
    printf("Thread 2 returns: %d\n", iret2);
    pthread_exit(NULL);
    
    return;
}

void *printHello(void *thread_arg) {
    thread_data_t *my_data;
    
    int taskid = 0, sum = 0;
    char hello_msg[255];
    
    my_data = (thread_data_t *) thread_arg;
    taskid = my_data->thread_id;
    sum = my_data->sum;
    strcpy(hello_msg, my_data->message);
    printf("taskid = %d, sum = %d, message=%s\n", taskid, sum, hello_msg);
    
    return NULL;
}

void class3() {
    pthread_t my_thread;
    thread_data_t my_thread_data;
    
    my_thread_data.message = malloc(sizeof(char)*255);
    
    my_thread_data.thread_id = 10;
    my_thread_data.sum = 35;
    my_thread_data.message = "Hello World";
    
    /*pthread_t my_id = */pthread_create(&my_thread, NULL, printHello, (void *)&my_thread_data);
    pthread_join(my_thread,NULL);
    pthread_exit(NULL);
    
    return;
}

void *hello_return(void *) {
    //allocate new string on heap with "Hello World!"
    //char *hello = strdup("Hello World!\n");
    char *hello = "Hello World!\n";
    
    return (void *) hello;
}

void class4() {
    char *str;
    pthread_t thread; //thread identifier
    
    //create new thread that runs hello_return without arguments
    pthread_create(&thread, NULL, hello_return, NULL);
    
    //wait until thread completes, assign return value to str
    pthread_join(thread, (void **) &str);
    printf("%s",str);
    pthread_exit(NULL);
    
    return;
}
