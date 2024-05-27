#include "jump.h"
#include <setjmp.h>
#include <stdlib.h>

static void class1();
jmp_buf buf;

void myFunction() {
    printf("in myfunction()\n");
    longjmp(buf,1);
    
    // NEVER REACHED
    printf("never see this line due to long jump\n");
}
int jumpClass() {
    class1();
    return 0;
}

void class1() {
    
    //setjmp is similar to try in C++
    //longjmp is similar to throw
    /*
    int i = setjmp(buf);
    printf("i=%d\n",i);
    
    if (i != 0) exit(0);
    
    longjmp(buf,42);
    printf("Does this line get printed?\n");
    */
    if(setjmp(buf))
        printf("back in main\n");
    else {
        printf("first time through\n");
        myFunction();
    }
    
    return;
}
/* example error recovery using setjmp and longjmp
switch(setjmp(jbuf)) {
    case 0:
        apple = *suspicious;
        break;
    case 1:
        printf("suspicious is indeed a bad pointer\n");
        break;
    default:
        die("unexpected value returned by setjmp");
}
*/