#include "debugGdb.h"

static void class1();
static void class2();

int debugGdbClass() {
    class1();
    class2();
    return 0;
}

void class1() {
    const int data[5] = {1, 2, 3, 4, 5};
    int i = 0, sum = 0;
    
    //for (i = 0; i >= 0; ++i)
    for (i = 0; i < 5; ++i)
        sum += data[i];
        
    printf ("sum = %i\n",sum);
    
    return;
}

struct date {
    int month;
    int day;
    int year;
};

struct date foo (struct date x) {
    ++x.day;
    return x;
};

void class2() {
    
    struct date today = {10, 11, 2014};
    //int         array[5] = {1, 2, 3, 4, 5};
    struct date *newdate, foo();
    //char        *string = "test string";
    //int         i = 3;
    
    newdate = (struct date *)malloc(sizeof(struct date));
    newdate->month = 11;
    newdate->day = 15;
    newdate->year = 2014;
    
    today = foo(today);
    
    free(newdate);
    return;
}