#include "variadicChallenge.h"
#include <stdarg.h>
#include <string.h>

static void challenge1();

int addingNumbers(char type, void *sum, int count, ...);
double calcAverage(char type, int count, ...);
int findMax(char type, void *max, int count, ...);
int findMin(char type, void *min, int count, ...);
void persPrint(char *string, ...);

int variadicChallengeFunc() {
    challenge1();
    return 0;
}

void challenge1() {
    int sum = 0, max = 0, min = 0;
    addingNumbers('i', &sum, 2,10,20);
    findMax('i',&max,2,10,20);
    findMin('i',&min,2,10,20);
    persPrint("Data Set: %d, %d\n",10,20);
    persPrint("Sum =\t%d\n",sum);
    persPrint("Avg =\t%f\n",calcAverage('i',2,10,20));
    persPrint("Min =\t%d\n",min);
    persPrint("Max =\t%d\n",max);

    addingNumbers('i', &sum, 3,10,20,30);
    findMax('i',&max,3,10,20,30);
    findMin('i',&min,3,10,20,30);
    persPrint("\nData Set: %d, %d, %d\n",10, 20, 30);
    persPrint("Sum =\t%d\n",sum);
    persPrint("Avg =\t%f\n",calcAverage('i',3,10,20,30));
    persPrint("Min =\t%d\n",min);
    persPrint("Max =\t%d\n",max);

    addingNumbers('i', &sum, 4,10,20,30,40);
    findMax('i',&max,4,10,20,30,40);
    findMin('i',&min,4,10,20,30,40);
    persPrint("\nData Set: %d, %d, %d, %d\n",10,20,30,40);
    persPrint("Sum =\t%d\n",sum);
    persPrint("Avg =\t%f\n",calcAverage('i',4,10,20,30,40));
    persPrint("Min =\t%d\n",min);
    persPrint("Max =\t%d\n",max);

    double v1 = 10.5, v2 = 2.5;
    int num1 = 6, num2 = 5;
    long num3 = 12L, num4 = 20L;
    persPrint("\nData Set: %f, %f, %f, %f\n", v1, 3.5, v2, 4.5);
    persPrint("Avg =\t%f\n",calcAverage('d',4,v1, 3.5, v2, 4.5));
    persPrint("\nData Set: %f, %f\n", 1.0, 2.0);
    persPrint("Avg =\t%f\n",calcAverage('d',2,1.0, 2.0));
    persPrint("\nData Set: %f, %f, %f, %f, %f\n", (double)num2, v2, (double)num1, (double)num3, (double)num4);
    persPrint("Avg =\t%f\n",calcAverage('d',5,(double)num2, v2, (double)num1, (double)num3, (double)num4));

    return;
}

int addingNumbers(char type, void *sum, int count, ...) {
    va_list parg;
    int i;

    va_start(parg,count);

    switch (type) {
        case 'i':
            *(int *)sum = 0;
            for(i = 0; i < count; ++i) {
                *(int *)sum += va_arg(parg,int);
            }
            break;
        case 'u':
            *(unsigned int *)sum = 0;
            for(i = 0; i < count; ++i) {
                *(unsigned int *)sum += va_arg(parg,unsigned int);
            }
            break;
        case 'l':
            *(long *)sum = 0;
            for(i = 0; i < count; ++i) {
                *(long *)sum += va_arg(parg,long);
            }
            break;
        case 'd':
            *(double *)sum = 0;
            for(i = 0; i < count; ++i) {
                *(double *)sum += va_arg(parg,double);
            }
            break;
        default:
            fprintf(stderr,"Unknown typing in addingNumbers function\n"); 
            return -1;
    }
    va_end(parg);
    
    return 0;
}

double calcAverage(char type, int count, ...) {
    va_list parg;
    int i;
    double sum = 0;

    va_start(parg,count);

    switch (type) {
        case 'i':
            for(i = 0; i < count; ++i) {
                sum += va_arg(parg,int);
            }
            break;
        case 'u':
            for(i = 0; i < count; ++i) {
                sum += va_arg(parg,unsigned int);
            }
            break;
        case 'l':
            for(i = 0; i < count; ++i) {
                sum += va_arg(parg,long);
            }
            break;
        case 'd':
            for(i = 0; i < count; ++i) {
                sum += va_arg(parg,double);
            }
            break;
        default:
            fprintf(stderr,"Unknown typing in calcAverage function\n"); 
            return -1;
    }
    va_end(parg);
    
    return sum/count;
}

int findMax(char type, void *max, int count, ...) {
    va_list parg;
    int i;

    va_start(parg,count);

    switch (type) {
        case 'i':
            *(int *)max = va_arg(parg,int);
            int itemp;
            for(i = 1; i < count; ++i) {
                itemp = va_arg(parg,int);
                if(itemp > *(int *)max) {
                    *(int *)max = itemp;
                }
            }
            break;
        case 'u':
            *(unsigned int *)max = va_arg(parg,unsigned int);
            unsigned int utemp;
            for(i = 1; i < count; ++i) {
                utemp = va_arg(parg,unsigned int);
                if(utemp > *(unsigned int *)max) {
                    *(unsigned int *)max = utemp;
                }
            }
            break;
        case 'l':
            *(long *)max = va_arg(parg,long);
            long ltemp;
            for(i = 1; i < count; ++i) {
                ltemp = va_arg(parg,long);
                if(ltemp > *(long *)max) {
                    *(long *)max = ltemp;
                }
            }
            break;
        case 'd':
            *(double *)max = va_arg(parg,double);
            double dtemp;
            for(i = 1; i < count; ++i) {
                dtemp = va_arg(parg,double);
                if(dtemp > *(double *)max) {
                    *(double *)max = dtemp;
                }
            }
            break;
        default:
            fprintf(stderr,"Unknown typing in findMax function\n"); 
            return -1;
    }
    va_end(parg);
    
    return 0;
}

int findMin(char type, void *min, int count, ...) {
    va_list parg;
    int i;

    va_start(parg,count);

    switch (type) {
        case 'i':
            *(int *)min = va_arg(parg,int);
            int itemp;
            for(i = 1; i < count; ++i) {
                itemp = va_arg(parg,int);
                if(itemp < *(int *)min) {
                    *(int *)min = itemp;
                }
            }
            break;
        case 'u':
            *(unsigned int *)min = va_arg(parg,unsigned int);
            unsigned int utemp;
            for(i = 1; i < count; ++i) {
                utemp = va_arg(parg,unsigned int);
                if(utemp < *(unsigned int *)min) {
                    *(unsigned int *)min = utemp;
                }
            }
            break;
        case 'l':
            *(long *)min = va_arg(parg,long);
            long ltemp;
            for(i = 1; i < count; ++i) {
                ltemp = va_arg(parg,long);
                if(ltemp < *(long *)min) {
                    *(long *)min = ltemp;
                }
            }
            break;
        case 'd':
            *(double *)min = va_arg(parg,double);
            double dtemp;
            for(i = 1; i < count; ++i) {
                dtemp = va_arg(parg,double);
                if(dtemp < *(double *)min) {
                    *(double *)min = dtemp;
                }
            }
            break;
        default:
            fprintf(stderr,"Unknown typing in findMax function\n"); 
            return -1;
    }
    va_end(parg);
    return 0;
}

void persPrint(char *string, ...) {
    va_list parg;
    char ch;
    int ret = 0;
    int charCnt = 0, charRead = 0;
    va_start(parg,string);

    ret = sscanf(string,"%c%n",&ch,&charRead);
    charCnt += charRead;
    
    while((ret != -1) && (ch != '\0')) {
        if(ch == '%') {
            sscanf(string+charCnt,"%c%n",&ch,&charRead);
            charCnt += charRead;
            switch (ch) {
                case '%': // percent sign
                    putchar('%');
                    break;
                case 'd': // integer
                    int itemp = va_arg(parg,int);
                    printf("%d",itemp);
                    break;
                case 'f': // double
                    double dtemp = va_arg(parg,double);
                    printf("%lf",dtemp);
                    break;
                case 'u': // unsigned int
                    unsigned int utemp = va_arg(parg,unsigned int);
                    printf("%u",utemp);
                    break;
                case 'l': // long
                    long ltemp = va_arg(parg,long);
                    printf("%ld",ltemp);
                    break;
                default:
                    putchar('?');
            }
        }
        else {
            putchar(ch);
        }
        ret = sscanf(string+charCnt,"%c%n",&ch,&charRead);
        charCnt += charRead;
    }
    va_end(parg);
    return;
}