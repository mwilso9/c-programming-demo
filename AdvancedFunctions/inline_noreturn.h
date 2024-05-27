#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

int inline_noreturnClass();
noreturn void funcEx2();


inline static void funcEx1() {
    //do something
    printf("running foo...\n");
}

