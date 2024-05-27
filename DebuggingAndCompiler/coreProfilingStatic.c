#include "coreProfilingStatic.h"

static void class1();
static void class2();

int coreProfilingStaticClass() {
    class1();
    class2();
    return 0;
}

void class1() {
    /* strored in read only part of data segment */
    char *str = "GfG";
    
    /* problem: trying to modify read only memory */
    *(str+1) = 'n';
    return;
}

void class2() {
    return;
}
