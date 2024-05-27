#include <stdio.h>
#include "header.h"
     
// void display(const int array[], int limit);

// char *strcat(char *restrict s1, const char * restric s2);

int constant(int argc, char **argv)
{
    const const const double pi = 3.141592654;
    
    const int days[12] = {31, 28, 31, 30};
    
    typedef const int zip;
    const zip q = 8;
    
    const float *pf; // pf points to a constant float value; value is constant
    float * const pt; // pt is a const pointer; address is constant
    const float * const ptr; //address and value are both constant
    float const *pfc; // same as const float *pfc
    
	return 0;
}

