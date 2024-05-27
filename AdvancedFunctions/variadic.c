#include "variadic.h"
#include <stdarg.h>
#include <math.h>

static void class1();
static void class2();

double average(double v1, double v2, ...);
double sample_stddev(int count, ...);

int variadicClass() {
    class1();
    class2();
    return 0;
}

void class1() {
    double v1 = 10.5, v2 = 2.5;
    int num1 = 6, num2 = 5;
    long num3 = 12L, num4 = 20L;
    
    printf("Average = %.2lf\n",average(v1, 3.5, v2, 4.5, 0.0));
    printf("Average = %.2lf\n",average(1.0, 2.0, 0.0));
    printf("Average = %.2lf\n",average((double)num2, v2, (double)num1, (double)num3, (double)num4, 0.0));
    
    return;
}

double average(double v1, double v2, ...) {
    va_list parg;           // Pointer for variable argument list
    double sum = v1 + v2;   // Accumulate sum of the arguments
    double value = 0.0;     // Argument value
    int count = 2;          // Count of number of arguments
    va_start(parg, v2);     // Initialize argument pointer
    
    // 0 is the fixed, sentinal value to indicate the end of the list, not part of average
    // assumed all values are double
    while((value = va_arg(parg,double)) != 0.0) {
        sum += value;
        ++count;
    }
    va_end(parg);
    return sum/count;
}

void class2() {
    printf("%f\n",sample_stddev(4, 25.0, 27.3, 26.9, 25.7));
    
    return;
}

double sample_stddev(int count, ...) {
    va_list args1, args2;
    double sum = 0;
    
    va_start(args1,count);
    va_copy(args2,args1);
    
    for(int i = 0; i < count; ++i) {
//        double num = va_arg(args1,double);
//        sum += num;
        sum += va_arg(args1,double);
    }
    va_end(args1);
    
    double mean = sum/count;
    
    double sum_sq_diff = 0;
    for(int i = 0; i < count; ++i) {
        double num = va_arg(args2, double);
        sum_sq_diff += (num-mean)*(num-mean);
    }
    va_end(args2);
    return sqrt(sum_sq_diff/count);
}
