#include "recursionChallenge.h"

static void challenge1();
static void challenge2();
static void challenge3();
int recursiveSum(int);
int recursiveGCD(int, int, int);
void reverseString(char *,int,int);
int findGCD(int,int);
char *reverse(char *);

int recursionChallengeFunc() {
    challenge1();
    challenge2();
    challenge3();
    return 0;
}

void challenge1() {
    //int i = 5;
    int i = 7;
    printf("Sum of 1 to %d = %d\n",i,recursiveSum(i));
    return;
}

int recursiveSum(int n) {
    if(n == 1)
        return 1;
    return n+recursiveSum(n-1);
}


#define min(i,j) (i < j ? i : j)
void challenge2() {
    //int i = 10, j = 50;
    int i = 6, j = 52;
    printf("GCD of %d and %d = %d\n",i,j,recursiveGCD(i,j,min(i,j)));
    printf("GCD of %d and %d = %d[teach]\n",i,j,findGCD(i,j));
    return;
}

int recursiveGCD(int n1, int n2, int denom) {
    if((n1 % denom == 0) && (n2 % denom == 0))
        return denom;
    return recursiveGCD(n1,n2,denom-1);
}

//teacher solution
int findGCD(int a, int b) {
    while(a != b) {
        if(a > b)
            return findGCD(a-b,b);
        else
            return findGCD(a,b-a);
    }
    return a;
}

void challenge3() {
    //char string[] = "studytonight";
    char string[] = "how is your day";
    printf("The original string is: %s\n",string);
    printf("The reverse string is: %s[teach]\n",reverse(string));
    reverseString(string,0,sizeof(string)/sizeof(char)-1);
    printf("The reverse string is: %s\n",string);
    return;
}

void reverseString(char *string,int pos,int len) {
    if(pos > (len-1)/2)
        return;
    char temp = '\0';
    temp = string[pos];
    string[pos] = string[len-pos-1];
    string[len-pos-1] = temp;
    reverseString(string,pos+1,len);
}

//teacher solution
char * reverse(char *str) {
    static int i = 0;
    static char rev[100];
    if(*str) {
        reverse(str+1);
        rev[i++] = *str;
    }
    return rev;
}
