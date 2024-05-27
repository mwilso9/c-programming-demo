#include "classChallenge.h"

static void challenge234(int argc, char **argv);
int sum(int,int,int);

int classChallenge(int argc, char **argv) {
    challenge234(argc, argv);
    return 0;
}

/* Challenge 1: compile from command line
 * -try changing object name
 * gcc main.c -o main.o
 * -add debugging information
 * gcc -g main.c
 * -add warnings
 * gcc -Wall main.c
 * -display warnings as errors
 * gcc -Wall -Werror main.c
 * */
 
// Challenge 2: preprocessor debugging
// Challenge 3: gdb debugging
// Challenge 4: coredump debugging
#ifdef DEBON_C
#  define DEBUG_C(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#else
#  define DEBUG_C(fmt,...)
#endif

#if defined(FIX1) || defined(FIX2)
#  define FIX
#else
#  define NO_FIX
#endif
int sum(int x, int y, int z) {
    char c = 2;
    #ifdef NO_FIX
    int *a = NULL;
    #endif
    //fix
    #ifdef FIX
    int a = 0;
    #endif
    
    DEBUG_C("c = %d\n",x);
    DEBUG_C("x = %d\n",x);
    DEBUG_C("y = %d\n",y);
    DEBUG_C("z = %d\n",z);
    #ifdef NO_FIX
    DEBUG_C("a = %ld\n",(long)a);
    #endif // NO_FIX
    #ifdef FIX
    DEBUG_C("a = %d\n",a);
    #endif // FIX
    
    #ifdef NO_FIX
    *a = 5;
    DEBUG_C("*a = %d\n",*a);
    #endif
    //fix
    #ifdef FIX
    a = 5;
    DEBUG_C("a = %d\n",a);
    #endif
    
    #ifdef NO_FIX
    return (c + x + y + z + *a)/3;
    #endif
    //fix
    #ifdef FIX
    return (c + x + y + z + a)/3;
    #endif
}
void challenge234(int argc, char **argv) {
    #ifndef FIX1
    int i, j, k;
    #endif
    // fix opt 1; not necessarily needed with argc check fix below
    #ifdef FIX1
    int i = 0, j = 0, k = 0;
    #endif
    #ifdef NO_FIX
    int result;
    #endif
    // fix; not necessarily needed since not used prior to setting; but good practice to initialize
    #ifdef FIX
    int result = 0;
    #endif
    
    #ifndef FIX2
    if(argc == 1) {
    #endif
    // fix opt 2; not necessarily needed if i,j,k are initialized above
    // if not fixed, need to check num for each atoi statement below
    #ifdef FIX2
    if(argc < 4) {
    #endif
        printf("Please specify three numbers as parameters.\n");
        exit(1);
    }
    DEBUG_C("Number of parameters = %d\n",argc);

    // fix opt 1
    #ifdef FIX1
    if(argc > 1) {
    #endif
        i = atoi(argv[1]);
        DEBUG_C("argv[1] = %s\n",argv[1]);
    #ifdef FIX1
    }
    // fix opt 1
    if(argc > 2) {
    #endif
        j = atoi(argv[2]);
        DEBUG_C("argv[2] = %s\n",argv[2]);
    #ifdef FIX1
    }
    // fix opt 1
    if(argc > 3) {
    #endif
        k = atoi(argv[3]);
        DEBUG_C("argv[3] = %s\n",argv[3]);
    #ifdef FIX1
    }
    #endif
    
    result = sum(i,j,12) + sum(j,k,19) + sum(i,k,13);
    
    printf("%d\n", result);
    
    return;
}