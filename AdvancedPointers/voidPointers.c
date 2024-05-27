#include "voidPointers.h"

static void class1();

int voidPointersClass() {
    class1();
    return 0;
}

void class1() {
    
    int i = 10;
    float f = 2.34;
    char c = 'k';
    
    void *vp = NULL;
    
    vp = &i;
    printf("Value of i = %d\n", *((int *)vp));
    
    vp = &f;
    printf("Value of f = %.2f\n", *((float *)vp));
    
    vp = &c;
    printf("Value of c = %c\n", *((char *)vp));
    return;
}

/* can also be used with function arguments
 *
void send(void *pData, int nLength) {
    return;
}

struct point_t {
    int x;
    int y;
};

main {
    char *data = "blah";
    send(data,strlen(data));
    
    struct point_t p;
    p.x = 1;
    p.y = 2;
    
    send(&p, sizeof(struct point_t));
}
*/