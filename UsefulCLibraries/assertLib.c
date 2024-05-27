#include "assertLib.h"
#include <math.h>
#include <limits.h>

static void class1();
static void class2();
static void class3();

int assertLibClass() {
    class1();
    class2();
    class3();
    return 0;
}

void class1() {
    int y = 5;
    
    for(int x = 0; x < 20; ++x) {
        printf("x = %d\ty = %d\n",x,y);
        assert(x < y);
    }
    return;
}

void class2() {
    double x,y,z;
    
    puts("Enter a pair of numbes (0 0 to quit): ");
    while(scanf("%lf%lf", &x, &y) == 2
            && (x != 0 || y != 0)) {
        z = x * x - y * y; // should be +
        assert(z >= 0);
        printf("answer is %f\n", sqrt(z));
        puts("Next pair of numbers: ");
    }
    puts("Done\n");
}

//static_assert(CHAR_BIT == 16, "16-bit char falsely assumed\n");
// static asserts are only with c11
void class3() {
    puts("char is 16 bits.\n");
    return;
}