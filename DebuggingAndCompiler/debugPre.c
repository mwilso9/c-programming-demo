#include "debugPre.h"

static void class1();
static void class2(int argc, char **argv);
static int process(int,int,int);
static int process2(int,int);

//#define DEBUG(fmt, ...) fprintf(stderr,fmt,__VA_ARGS__)
//#define DEBUG(fmt, ...)


/* using Debug global variable as varying levels of debugging */
int debug_level = 0;
#ifdef DEBON
#  define DEBUG(level, fmt, ...) \
    if(debug_level >= level) \
        fprintf(stderr, fmt, __VA_ARGS__)
#else
#  define DEBUG(level, fmt, ...)
#endif // DEBON

int process(int i, int j, int k) {
    return i + j + k;
}

int process2(int i, int j) {
    int val = 0;
    
//    #ifdef DEBUG
        DEBUG(2, "process(%d,%d)\n",i,j);
//    #endif // DEBUG
    
    val = i * j;
    
//    #ifdef DEBUG
        DEBUG(1, "return %d\n",val);
//    #endif // DEBUG
    
    return val;
}

int debugPreClass(int argc, char **argv) {
    class1();
    class2(argc,argv);
    return 0;
}

void class1() {
    int i, j, k, nread;
    i = debug_level; // just to suppress unused variable warning
    
    nread = scanf("%d %d %d",&i,&j,&k);
    
    #ifdef DEBUG
        fprintf(stderr,"Number of integers read = %i\n",nread);
        fprintf(stderr,"i = %i, j = %i, k = %i\n",i,j,k);
    #endif // DEBUG
    
    printf("processed = %d\n",process(i,j,k));
    return;
}

void class2(int argc, char **argv) {
    int arg1 = 0, arg2 = 0;
    
    #ifdef DEBON
    if(argc > 1)
        debug_level = atoi(argv[1]);
    if(argc > 2)
        arg1 = atoi(argv[2]);
    if(argc == 4)
        arg2 = atoi(argv[3]);
    #else
    if(argc > 1)
        arg1 = atoi(argv[1]);
    if(argc == 3)
        arg2 = atoi(argv[2]);
    #endif // DEBON
    
//    #ifdef DEBUG
        DEBUG(0, "debug level = %i\n", debug_level)
        DEBUG(1, "processed %i arguments\n", argc - 1);
        DEBUG(3, "arg1 = %i, arg2 = %i\n", arg1, arg2);
//    #endif // DEBUG
    
    printf("%i\n",process2(arg1,arg2));
    
    return;
}