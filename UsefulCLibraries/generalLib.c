#include "generalLib.h"
#include <time.h>
#include <string.h>
#include <assert.h>

#define SIZE 10
/* stdlib contains various useful general utilities
 *  random number generators
 *      rand, srand
 *  program termination functions
 *      exit, atexit, abort
 *  searching and sorting functions
 *      qsort
 *  conversion functions
 *      atoi, atof, atol, strtod, strtof, strtol, itoa
 *  memory management functions
 *      system, getenv
 *  string functions
 *      memcopy, memmove, strdup, strndup
 */

static void class1();
static void class2();
static void class3();
static void class4();
static void class5();
static void class6();

void sign_off(void);
void too_bad(void);
int comp_ints(const void *, const void *);
void show_array(const int[], int);

int generalLibClass() {
    class1();
    class2();
    class3();
    class4();
    class5();
    class6();
    return 0;
}

void class1() {
    //exit(EXIT_FAILURE); //non-zero value
    //exit(EXIT_SUCCESS); //zero value
    
    int n = 0;
    
    atexit(sign_off);
    puts("Enter an integer:");
    
    if(scanf("%d",&n) != 1) {
        puts("That's no integer!");
        atexit(too_bad);
        exit(EXIT_FAILURE);
    }
    
    //abort(); // typically used with fatal errors and do not want to proceed further, causes coredump
    
    return;
}

void sign_off() {
    puts("in sign_off..");
}

void too_bad() {
    puts("in too_bad.");
}

void class2() {
    int data[5] = {54, 3, 12, 9, 24};
    qsort(data, 5, sizeof(int), comp_ints);
    
    for(int i = 0; i < 5; i++)
        printf("%d\n", data[i]);
}

int comp_ints(const void *p1,const void *p2) {
    const int i1 = *(const int *) p1;
    const int i2 = *(const int *) p2;
    return i1 - i2;
}

void class3() {
    char a[] = "3.14";
    int vali = atoi(a);
    float valf = atof(a);
    long int vall = atol(a);
    char b[] = "365.25 7.0", *end;
    double val2d = 0;
    float val2f = 0;
    long int val2l = 0;

    printf("Value = %d\n", vali);
    printf("Value = %.2f\n", valf);
    printf("Value = %ld\n", vall);
    
    val2d = strtod(b, &end);
    val2f = strtof(end, NULL);
    val2l = strtol(b, &end, 16);
    printf("Value = %lf\n", val2d);
    printf("Value = %f\n", val2f);
    printf("Value = %ld\n", val2l);
    
    //itoa and ltoa convert numbers to strings,
    //but they are not standard so compilers may not support them.
    //should use sprintf instead
    
    /*********************************************************/
    srand(time(0));
    for(int i = 0; i < 5; i++) {
        printf("%d\t", rand() % 10);
    }
    printf("\n");
    
    return;
}

void class4() {
    char command[50];
    char *str = NULL;
    strcpy(command, "pwd");
    system(command);
    puts("\n");
    
    assert((str = getenv("HOME")) != NULL);
    printf("Value of \"HOME Environment Variable\" : %s\n", str);

    assert((str = getenv("PATH")) != NULL);
    printf("Value of \"PATH Environment Variable\" : %s\n", str);

    return;
}


void class5() {
    int values[SIZE] = {1,2,3,4,5,6,7,8,9,10};
    int target[SIZE];
    double curious[SIZE/2] = {2.0, 2.0e5, 2.0e10, 2.0e20, 5.0e30};
    
    puts("memcpy() used:");
    puts("values (original data): ");
    show_array(values,SIZE);
    memcpy(target,values,SIZE*sizeof(int));
    puts("target (copy of values):");
    show_array(target,SIZE);
    
    puts("\nUsing memmove() with overlapping ranges:");
    memmove(values+2,values,5*sizeof(int));
    puts("values -- elements 0-5 copied to 2-7:");
    show_array(values,SIZE);
    
    assert(sizeof(double) == 2*sizeof(int));
    puts("\nUsing memcpy() to copy double to int:");
    memcpy(target,curious, (SIZE/2)*sizeof(double));
    puts("target -- 5 doubles into 10 int positions:");
    show_array(target,SIZE/2);
    show_array(target+5,SIZE/2);
    
    return;
}

void show_array(const int ar[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", ar[i]);
    putchar('\n');
}

void class6() {
// stdup and stdnup are not standard and may not be supported
/*    char *p1 = "Jason";
    char *p2 = NULL;
    
    p2 = stdup(p1);
    printf("Duplicated string is : %s", p2);
    
    free(p2);
    p2 = stdnup(p1,3);
    printf("Duplicated string is : %s", p2);
    
    free(p2);
*/
    return;
}
