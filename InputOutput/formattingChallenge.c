#include "charChallenge.h"

static void challenge1(char *filename);
int checkNum(int val);
int isPrime(int val);

int formattingChallengeFunc() {
    challenge1("C:\\Users\\mugiw\\Documents\\Workspaces\\Workspace2\\InputOutput\\numbers.txt");
    return 0;
}

#define MAX 255
#define PRIME   0
#define ODD     1
#define EVEN    2
void challenge1(char *filename) {
    FILE *fpIn = NULL;
    FILE *fpOut = stdout;
    char ch[MAX];
    int val = 0;
    int bytes_now = 0;
    int bytes_consumed = 0;

    if((fpIn = fopen(filename,"r"))==NULL){
        fprintf(stderr,"File '%s' not found. Exiting...\n",filename);
        return;
    }
    fprintf(fpOut,"File opened successfully. Reading integers from file\n");
    fprintf(fpOut,"\nUsing fscanf\n");
    while(!feof(fpIn)) {
        if(fscanf(fpIn,"%d",&val) != -1) {
            switch(checkNum(val)) {
                case PRIME:
                    fprintf(fpOut,"Prime");
                    break;
                case EVEN:
                    fprintf(fpOut,"Even");
                    break;
                case ODD:
                    fprintf(fpOut,"Odd");
                    break;
                default:
                    fprintf(fpOut,"Unknown");
            }
            fprintf(fpOut," number found:\t%d\n",val);
        }
    }
    
    rewind(fpIn);
    fprintf(fpOut,"\nUsing fgets and sscanf\n");
    while(!feof(fpIn)) {
        if(fgets(ch,MAX,fpIn) != NULL) {
            bytes_consumed = 0;
            while(sscanf(ch+bytes_consumed,"%d%n",&val,&bytes_now) > 0) {
                switch(checkNum(val)) {
                    case PRIME:
                        fprintf(fpOut,"Prime");
                        break;
                    case EVEN:
                        fprintf(fpOut,"Even");
                        break;
                    case ODD:
                        fprintf(fpOut,"Odd");
                        break;
                    default:
                        fprintf(fpOut,"Unknown");
                }
                fprintf(fpOut," number found:\t%d\n", val);
                bytes_consumed += bytes_now;
            }
        }
    }

    fclose(fpIn);
    
    return;
}

#define isEven(num) (num % 2 == 0)
#define isOdd(num)  (num % 2 == 1)
int checkNum(int val) {
    if(isPrime(val) == 1)
        return PRIME;
    else if(isEven(val))
        return EVEN;
    else if(isOdd(val))
        return ODD;
    else
        return -1;
}

int isPrime(int val) {
    if(val < 0) return 0;
    for(int i = 2; i <= val/2; i++) {
        if(val % i == 0) {
            return 0;
        }
    }
    return 1;
}