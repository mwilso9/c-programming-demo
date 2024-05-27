#include "preprocessor.h"
#include <stdlib.h>

static void class1();

int preprocessorClass() {
    class1();

    return 0;
}

#define JUST_CHECKING
#define LIMIT 4
//#pragma GCC poison printf
void class1() {
    int i = 0;
    int total = 0;
    
    for(i = 1; i <= LIMIT; i++) {
        total += 2*i*i + 1;
        
        #ifdef JUST_CHECKING
            printf("i=%d, running total = %d\n",i,total);
        #endif
    }
    
    printf("Grand total = %d\n",total);
    return;
}

