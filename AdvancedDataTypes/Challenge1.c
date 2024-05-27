#include <stdio.h>
#include "advancedDataTypes.h"

int ADTchallenge1() {
	int i, total = 0, num = 0;
	
	printf("Enter num of elements: ");
	scanf("%d",&num);

	int array[num];
	for(i = 0; i < num; i++) {
		printf("\nEnter element %d: ",i);
		scanf("%d",&(array[i]));
	}
	
	for(i = 0; i < num; i++) {
		total = total + array[i];
	}
	
	printf("\nTotal = %d\n",total);
	
	return 0;
}
