#include <stdio.h>
#include <malloc.h>

void f1(int n, float *restrict a1, const float * restrict a2)
{
    int i;
    for (i = 0; i < n; i++)
        a1[i] += a2[i];
}

int main(int argc, char **argv)
{
    volatile const int loc;
    const volatile int * ploc;
    
    int n;
    int array[10] = {0};
    int * restrict restar = (int *) malloc(10*sizeof(int));
    int * par = array;
    
    for (n = 0; n < 10; n++) {
        par[n] += 5;
        restar[n] += 5;
        array[n] *= 2;
        par[n] += 3;
        restar[n] += 3;
        // compiler would optomize restrict to single statemnt
        // restar[n] += 8
        //
        // cannot do same with par since is not restrict
        // would also be incorrect since value is doubled via
        // "array[n] *= 2"
        printf("array[%d] = %d, ",n,array[n]);
        printf("par[%d] = %d, ",n,par[n]);
        printf("restar[%d] = %d\n",n,restar[n]);
    }
    
    free(restar);
    
	return 0;
}

//void *memcpy(void * restrict s1, const void * restrict s2, size_t n);
//void *memmove(void * s1, const void * s2, size_t n);
