#include "unions.h"
#include <stdlib.h>

static void class1();
static void class2();

union car {
    int i_value;
    float f_value;
    char c_value[40];
};

int unionsClass() {
    class1();
    class2();
    return 0;
}

void class1() {
    union car car1, car2, *car3;
    printf("Memory size occupied by car: %zu\n", sizeof(car1));
    car2.i_value = (int) sizeof(car3);
    car3 = &car2;
    return;
}
/*****************/
struct owner {
    char socsecurity[12];
};

struct leasecompany {
    char name[40];
    char headquarters[40];
};

struct car_data {
    char make[15];
    int status; /* 0 = owned, 1 = leased */
    union {
        struct owner owncar;
        struct leasecompany leasecar;
    };
};
/******************/

union mixed {
    char c;
    float f;
    int i;
};


void class2() {
    union mixed x;

    //x.c = 'j';
    //x.f = 2.2;
    x.i = 48;
    printf("Character = %c\n",x.c);
    printf("Float = %f\n",x.f);
    printf("Integer = %i\n",x.i);
    return;
}
