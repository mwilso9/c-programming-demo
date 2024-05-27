#include "goto.h"

static void class1();

int gotoClass() {
    class1();
    return 0;
}

void class1() {
    const int maxInput = 5;
    int i = 0;
    double num, avg = 0.0, sum = 0.0;
    
    for(i=1; i<=maxInput; ++i)
    {
        printf("%d. Enter a number: ", i);
        scanf("%lf",&num);
        
        if(num < 0.0)
            goto jump;
        sum += num;
    }
    
    jump:
        avg=sum/(i-1);
        printf("Sum = %.2f\n", sum);
        printf("Average = %.2f\n",avg);
    
    return;
}