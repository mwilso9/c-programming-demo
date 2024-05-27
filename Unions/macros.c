#include "macros.h"
#include <stdlib.h>

static void class1();
static void class2();
static void class3();
static void class4();
static void challenge1();
static void challenge2();
static void challenge3();
static void challenge4();

int macrosClass() {
    class1();
    class2();
    class3();
    class4();
    return 0;
}

#define PI 3.14
#define PRNT(a,b) \
    printf("value 1 = %d\n",a); \
    printf("value 2 = %d\n",b);

void class1() {
    int x = 2, y = 3;
    PRNT(x,y);
    return;
}

#define CIRCLE_AREA(x) ((PI)*SQUARE(x))
#define WARNING(...) fprintf(stderr, __VA_ARGS__)
//#define WARNING(format, ...) fprintf(format, stderr, __VA_ARGS__)
#define SQUARE(x) ((x)*(x))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define UpTo(i,n) for((i)=0; (i)<(n); (i)++)

void class2() {
    int area = CIRCLE_AREA(4);
    int i;
    printf("Area is %d\n",area);    

    WARNING("%s: this program is here\n","Jason");
    
    UpTo(i,10) {
        PRNT(SQUARE(i),10);
        printf("max value = %d\n",MAX(SQUARE(i),10));
    }
    
    return;
}

#define MIN(x,y) \
    ((x)<(y)?(x):(y))

#if defined (WINDOWS) || defined (WINDOWSNT)
#  define BOOT_DRIVE "C:/"
#else
#  define BOOT_DRIVE "D:/"
#endif

#define STR(x) #x
#define HELLO(x) printf("Hello, " #x "\n");
#define PRINTINT(var) printf(#var " = %i\n",var)
#define CONCATENATE(x,y) x##y

/*struct command {
    char *name;
    void (*function) (void);
};
#define COMMAND(name) {#name, name ## _command}
struct command commands[] = {
    COMMAND(quit) //{"quit",quit_command},
    COMMAND(help) //{"help",help_command}
};*/

void class3() {
    int count = 3;
    int xy=10;
    printf("Here is the boot drive path: %s\n",BOOT_DRIVE);
    HELLO(John);
    PRINTINT(count);
    PRINTINT(CONCATENATE(x,y));
    return;
}

void class4() {
    printf("filename:\t%s\nfunction:\t%s\nline:\t%d\n",__FILE__,__func__,__LINE__);
    
    #if (__STDC__ == 1)
        printf("Implementation is ISO-conforming.\n");
    #else
        printf("Implementation is not ISO-conforming.\n");
    #endif
    
    printf("Program last compiled at %s on %s\n",__TIME__,__DATE__);
    return;
}

int macrosChallenge() {
    printf("\tchallenge 1\n");
    challenge1();
    printf("\n\tchallenge 2\n");
    challenge2();
    printf("\n\tchallenge 3\n");
    challenge3();
    printf("\n\tchallenge 4\n");
    challenge4();
    return 0;
}

//#define PRINTINT(var) printf(#var " = %i\n",var) //commented out due to defining above
#define PRINTSTRING(var) printf(#var " = %s\n",var)
void challenge1() {
    PRINTINT(__LINE__);
    PRINTSTRING(__FILE__);
    PRINTSTRING(__DATE__);
    PRINTSTRING(__TIME__);
    PRINTINT(__STDC__);
    return;
}

#define SUM(a,b) ((a)+(b))
void challenge2() {
    int x = 5, y = 10;
    PRINTINT(x);
    PRINTINT(y);
    PRINTINT(SUM(x,y));
    return;
}

// #define SQUARE(x) ((x)*(x)) //commented out due to defining above
#define CUBE(x) ((x)*(x)*(x))
void challenge3() {
    int x = 10;
    PRINTINT(x);
    PRINTINT(SQUARE(x));
    PRINTINT(CUBE(x));
    return;
}

#define IS_UPPER(c) (((c)>='A') && ((c)<='Z'))
#define IS_LOWER(c) (((c)>='a') && ((c)<='z'))
#define IS_DIGIT(c) (((c)>='0') && ((c)<='9'))
#define IS_VOWEL_LOWER(c) (((c)=='a') || ((c)=='e') || \
                           ((c)=='i') || ((c)=='o') || \
                           ((c)=='u') || ((c)=='y'))
#define IS_VOWEL_UPPER(c) (((c)=='A') || ((c)=='E') || \
                           ((c)=='I') || ((c)=='O') || \
                           ((c)=='U') || ((c)=='Y'))
#define IS_VOWEL(c) ((IS_VOWEL_UPPER(c)) || (IS_VOWEL_LOWER(c)))
#define IS_ALPHABET(c) ((IS_UPPER(c)) || (IS_LOWER(c)))
#define IS_ALPHANUMERIC(c) ((IS_ALPHABET(c)) || (IS_DIGIT(c)))
#define IS_CONSONANT(c) ((IS_ALPHABET(c)) && (!IS_VOWEL(c)))

void challenge4() {
    char test[] = "Matt Wilson - 489";
    int len = sizeof(test)/sizeof(char);
    
    for(int i = 0; i < len - 1; i++) {
        if(!IS_ALPHANUMERIC(test[i])) {
            printf("'%c' is not in the alphabet nor a number\n",test[i]);
        }
        else {
            if(!IS_ALPHABET(test[i])) {
                printf("'%c' is not in the alphabet\n",test[i]);
            }
            else {
                if(IS_UPPER(test[i]))
                    printf("'%c' is uppercase\n",test[i]);
                else if(IS_LOWER(test[i]))
                    printf("'%c' is lowercase\n",test[i]);
                if(IS_VOWEL(test[i]))
                    printf("'%c' is a vowel\n",test[i]);
                else if(IS_CONSONANT(test[i]))
                    printf("'%c' is a consonant\n",test[i]);
            }
            if(IS_DIGIT(test[i]))
                    printf("'%c' is a number\n",test[i]);
        }
    }
    
    return;
}

