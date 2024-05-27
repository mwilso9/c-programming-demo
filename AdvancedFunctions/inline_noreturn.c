#include "inline_noreturn.h"

static void class1();

int inline_noreturnClass() {
    class1();
    return 0;
}

void class1() {
    funcEx1();
    funcEx2();
    return;
}

void funcEx2() {
    //do something
    printf("running foo2...\n");
    //return;
    abort();
}
