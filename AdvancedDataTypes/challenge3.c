#include <stdio.h>
#include <complex.h>
#include <math.h>
#include "advancedDataTypes.h"

int ADTchallenge3() {

    double complex a_mult, a_sq, a_e, a_con, b_con, c_con;
    
    a_mult = I*I;
    a_sq = pow(I,2);
    a_e = exp(I*acos(-1));
    a_con = conj(1+2*I);
    b_con = conj(1-2*I);
    c_con = (1+2*I)*(1-2*I);
    
    
    printf("I*I = %.0f%+.0fi\n",creal(a_mult),cimag(a_mult));
    printf("I^2 = %.0f%+.0fi\n",creal(a_sq),cimag(a_sq));
    printf("e^(I*PI) = %.0f%+.0fi\n",creal(a_e),cimag(a_e));
    printf("conj(1+2*I) = %.0f%+.0fi\n",creal(a_con),cimag(a_con));
    printf("conj(1-2*I) = %.0f%+.0fi\n",creal(b_con),cimag(b_con));
    printf("(1+2*I)*(1-2*I) = %.0f%+.0fi\n",creal(c_con),cimag(c_con));
    return 0;
}