#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "advancedDataTypes.h"

struct myArray {
    int length;
    int array[];
};

int ADTchallenge2() {
	int i,size = 0;
    struct myArray *flexArr = NULL;
	
	printf("Enter num of elements: ");
	scanf("%d",&size);

	flexArr = malloc(sizeof(struct myArray) + size*sizeof(int));
    flexArr->length = size;
	for(i = 0; i < flexArr->length; i++) {
		printf("\nEnter element %d: ",i);
		scanf("%d",&(flexArr->array[i]));
	}
	
	for(i = 0; i < flexArr->length; i++) {
		printf("\n%d",flexArr->array[i]);
	}
	
    free(flexArr);
    return 0;
}