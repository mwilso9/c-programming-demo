#include "doublePointers.h"
#include <malloc.h>
#include <string.h>

static void class1();
static void class2();
static void class3();
static void challenge1();
static void challenge2();
void foo(int *);
void foo2(int **);
void charfoo(char **);
void allocateMemory(int **);

int doublePointersClass() {
    class1();
    class2();
    class3();
    return 0;
}

int doublePointersChallenge() {
    challenge1();
    challenge2();
    return 0;
}

void class1() {
    int a = 10;
    int *p1 = NULL;
    int **p2 = NULL;
    
    p1 = &a;
    p2 = &p1;

    printf("Address of a = %u\n", &a);
    printf("Address of p1 = %u\n", &p1);
    printf("Address of p2 = %u\n\n", &p2);
    // below print statements will give the address of 'a'
    printf("Value at the address stored by p2 = %u\n", *p2);
    printf("Value at the address stored by p1 = %d\n\n", *p1);
    printf("Value of **p2 = %d\n", **p2); //read this *(*p2)

    return;
}

/* use cases for double pointers:
 *  change value of pointer passed to a function (simulate pass by reference).
 *  used to preserve memory allocation or assignment even outside the function
 * */
void foo(int *ptr) {
     int a = 5;
     ptr = &a;
}
void foo2(int **ptr) {
     int a = 5;
     *ptr = &a;
}
void class2() {
    int *ptr = NULL;
    ptr = (int *) malloc(sizeof(int));
    *ptr = 10;

    printf("pre\t%d\n",*ptr);
    
    foo(ptr);
    printf("foo\t%d\n",*ptr);

    foo2(&ptr);
    printf("foo2\t%d\n",*ptr);

    return;
}

void charfoo(char **ptr) {
    *ptr = malloc(255);
    strcpy(*ptr, "Hello World");
}

void class3() {
    char *ptr = NULL;
    
    charfoo(&ptr);
    printf("%s\n",ptr);
    free(ptr);
    
    return;
}

void challenge1() {
    int var = 10;
    int *ptr = &var;
    int **dptr = &ptr;
    
    printf("Value of normal integer variable:\n");
    printf("\tvar =\t%d\n", var);
    printf("\t*ptr =\t%d\n", *ptr);
    printf("\t**dptr =\t%d\n", **dptr);
    
    printf("Address of normal integer variable:\n");
    printf("\t&var =\t%u\n", &var);
    printf("\tptr =\t%u\n", ptr);
    printf("\t*dptr =\t%u\n", *dptr);
    
    printf("Value of single pointer variable:\n");
    printf("\tptr =\t%u\n", ptr);
    printf("\t*dptr =\t%u\n", *dptr);
    
    printf("Address of single pointer variable:\n");
    printf("\t&ptr =\t%u\n", &ptr);
    printf("\tdptr =\t%u\n", dptr);
    
    printf("Value of double pointer variable:\n");
    printf("\tdptr =\t%u\n", dptr);
    
    printf("Address of double pointer variable:\n");
    printf("\t&dptr =\t%u\n", &dptr);
    
    return;
}

void allocateMemory(int **ptr) {
    *ptr = (int *) malloc(sizeof(int));
}

// original output is seg fault/mem leak due to function copy being allocated, not original
// modified output is value of assignment due to memory allocation preservation from using double pointers
void challenge2() {
    int *ptr = NULL;
    
    allocateMemory(&ptr);
    
    *ptr = 10;
    printf("%d\n",*ptr);
    free(ptr);
    
    return;
}