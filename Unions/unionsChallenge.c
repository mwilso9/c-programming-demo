#include "unionsChallenge.h"

static void challenge1();

int unionsChallengeFunc() {
    challenge1();
    return 0;
}

union student {
    char letterGrade;
    int roundedGrade;
    float exactGrade;
};

void challenge1() {
    union student var1, var2, *var3;
    
    var1.letterGrade = 'F';
    var1.roundedGrade = 45;
    var1.exactGrade = 44.67895;
    printf("Student 1's grade is...\n");
    printf("\tLetter:\t%c\n",var1.letterGrade);
    printf("\tRound:\t%d\n",var1.roundedGrade);
    printf("\tExact:\t%f\n",var1.exactGrade);
    
    var3 = &var2;
    printf("Student 2's grade is...\n");
    var2.letterGrade = 'A';
    printf("\tLetter:\t%c\n",var3->letterGrade);
    var2.roundedGrade = 94;
    printf("\tRound:\t%d\n",var3->roundedGrade);
    var2.exactGrade = 94.4235;
    printf("\tExact:\t%f\n",var3->exactGrade);
    
    return;
}