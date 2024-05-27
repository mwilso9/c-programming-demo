#include "threadFunc.h"
#include <pthread.h>
#include <unistd.h>

static void class1();
static void class2();
static void class3();
static void class4();

void *calls(void *);
void *threadFn(void *);
void *dowork(void *);
void *my_function(void*);

pthread_attr_t attr;

int threadFuncClass() {
    class1();
    class2();
    class3();
    
    /*no examples, but pthread_equal compares to thread ids and pthread_once executes a function exactly once (subsequent calls will have no effect)
     *  int pthread_equal(pthread_t thread1, pthread_t thread2)
     *      returns 0 if different, otherwise is non-zero
     *  pthread_once(once_control, init_routine)
     *      once_control is a pthread_once_t macro value (ex: pthread_once_t once_control = PTHREAD_ONCE_INIT;)
     *      init_routine is the initialization function to be run
     */
    
    
    class4();
    return 0;
}

void *calls(void *ptr) {
    //using pthread_self() to get current thread id
    printf("In function \nthread id = %ld\n", (long int) pthread_self());
    pthread_exit(NULL);
    return NULL;
}

void class1() {
    pthread_t thread; //declare thread
    pthread_create(&thread, NULL, calls, NULL);
    printf("In main \nthread id = %ld\n", (long int) thread);
    pthread_join(thread,NULL);
    return;
}

void *threadFn(void *arg) {
    pthread_detach(pthread_self());
    sleep(3);
    printf("Thread Fn\n");
    pthread_exit(NULL);
}

void class2() {
    pthread_t tid;
    int ret = pthread_create(&tid, NULL, threadFn, NULL);
    
    if(ret != 0) {
        perror("Thread Creation Error\n");
        exit(1);
    }
    
    printf("After thread created in Main\n");
    pthread_exit(NULL);
    return;
}

void *dowork(void *threadid) {
    long tid;
    size_t mystacksize;
    
    tid = (long)threadid;
    pthread_attr_getstacksize (&attr, &mystacksize);
    
    printf("Thread %ld: stack size = %li bytes \n", tid, mystacksize);
    
    pthread_exit(NULL);
    return NULL;
}

void class3() {
    pthread_t myThread;
    size_t stacksize;
    int myID;
    long t = 0;
    
    pthread_attr_init(&attr);
    pthread_attr_getstacksize(&attr, &stacksize);
    printf("Default stack size = %li\n", stacksize);
    stacksize = 9000000;
    printf("Amount of stack needed per thread = %li\n", stacksize);
    pthread_attr_setstacksize(&attr, stacksize);
    
    printf("Creating thread with stack size = %li bytes\n", stacksize);
    myID = pthread_create(&myThread, &attr, dowork, (void *)t);
    
    if(myID) {
        printf("Error: return code from pthread_create() is %lud\n", (long unsigned int) myID);
        exit(-1);
    }
    pthread_exit(NULL);
    return;
}

void *my_function(void*) {
    printf("Hello World");
    pthread_cancel(pthread_self());
    return NULL;
}

void class4() {
    pthread_t thread = NULL;
    
    pthread_create(&thread, NULL, my_function, NULL);
    pthread_join(thread, NULL);
    return;
}
