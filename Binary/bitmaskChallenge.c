#include "bitmaskChallenge.h"

static void challenge1();

int bitmaskChallengeFunc() {
    challenge1();
    return 0;
}

void challenge1() {
    int num = 0, bit = 0, result = 0, mask = 0;
    
    printf("Enter any number: ");
    scanf("%d",&num);
    printf("Enter nth bit to check and set (0-31): ");
    scanf("%d",&bit);
    printf("\n");
    if((bit >= 0) && (bit <= 31)) {
        mask = 1<<bit;
        if((num&mask)==mask) // prof demo sets status to "(num >> bit) & 1" instead of using mask
            printf("The %d bit of %d is set to 1\n",bit,num);
        else {
            printf("The %d bit of %d is set to 0\n",bit,num);
            result = num | mask;
            printf("Bit set successfully.\n");
            printf("Number before setting %d bit: %d\n",bit,num);
            printf("Number after setting %d bit: %d\n",bit,result);
        }
    }
    else
        printf("Invalid bit\n");
    return;
}