#include "recursion.h"
#include <stdlib.h>

static void class1();
int factorial (int n);
void upAndDown(int);

int recursionClass() {
    class1();
    return 0;
}

void class1() {
    for(int j = 0; j<8; j++)
        printf("%d! = %d\n", j, factorial(j));
    
    upAndDown(1);
    return;
}

int factorial(int n) {
    if(n == 0)
        return 1;
    else
        return n*factorial(n-1);
}

void upAndDown(int n) {
    printf("Level %d: n location %p\n",n,&n);
    if(n<4)
        upAndDown(n+1);
    printf("LEVEL %d: n location %p\n",n,&n);
}