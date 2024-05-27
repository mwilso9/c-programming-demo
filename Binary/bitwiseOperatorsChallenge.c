#include "bitwiseOperatorsChallenge.h"

static void challenge1();

int bitwiseChallengeFunc() {
    challenge1();
    return 0;
}

void challenge1() {
    int i1 = 0, i2 = 0;
    unsigned int lshift = 0, rshift = 0;
    int result = 0;
    
    printf("Enter 1st number: ");
    scanf("%d",&i1);
    printf("Enter 2nd number: ");
    scanf("%d",&i2);
    printf("Enter left shift amount: ");
    scanf("%d",&lshift);
    printf("Enter right shift amount: ");
    scanf("%d",&rshift);
    printf("\n");
    
    result = ~i1;
    printf("~%d = ~0b%lld = %d = 0b%lld\n",i1,convertDecToBin(i1),result,convertDecToBin(result));
    result = ~i2;
    printf("~%d = ~0b%lld = %d = 0b%lld\n",i2,convertDecToBin(i2),result,convertDecToBin(result));
    result = i1&i2;
    printf("%d & %d = %d = 0b%lld\n",i1,i2,i1&i2,convertDecToBin(result));
    result = i1|i2;
    printf("%d | %d = %d = 0b%lld\n",i1,i2,i1|i2,convertDecToBin(result));
    result = i1^i2;
    printf("%d ^ %d = %d = 0b%lld\n",i1,i2,i1^i2,convertDecToBin(result));
    result = i1<<lshift;
    printf("%d << %u = 0b%lld << %u = %d = 0b%lld\n",i1,lshift,convertDecToBin(i1),lshift,result,convertDecToBin(result));
    result = i2>>rshift;
    printf("%d >> %u = 0b%lld >> %u = %d = 0b%lld\n",i2,rshift,convertDecToBin(i2),rshift,result,convertDecToBin(result));
}