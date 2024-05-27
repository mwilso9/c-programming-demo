#include "gotoChallenge.h"

static void challenge1();
#define HEIGHT 5
#define BASE_WIDTH 2*HEIGHT-1
#define MIDPOINT (BASE_WIDTH-1)/2

int gotoChallengeFunc() {
    printf("my code\n");
    challenge1();
    printf("demo code\n");
    challengedemo();
    return 0;
}

/*
 * 0:0123*5678  star @ 4
 * 1:012*4*678  star @ 3,5
 * 2:01*345*78  star @ 2,6
 * 3:0*23456*8  star @ 1,7
 * 4:*********  star @ 0-8
*/
void challenge1() {
    
    int line = 0;
    int index = 0;
    
    print_line:
        if(line == HEIGHT)
            goto the_end;
        else if(index == BASE_WIDTH)
            goto end_of_line;
        else if(line == HEIGHT-1)
            goto print_star;
        else if((index == MIDPOINT-line) || (index == MIDPOINT+line))
            goto print_star;
        else
            goto print_space;
    
    print_space:
        printf(" ");
        index++;
        goto print_line;

    print_star:
        printf("*");
        index++;
        goto print_line;
        
    end_of_line:
        printf("\n");
        line++;
        index = 0;
        goto print_line;

    the_end:
    
    return;
}

void challengedemo() {
    int value = 5;
    int i = 1, j, k = 0;
    
    outerLoop:
        if(i < value) {
            j = i;
            
        innerLoop:
            if(j < value) {
                printf(" ");
                j++;
                goto innerLoop;
            }
            else {
                innerLoop2:
                    if(k != ((2 * i))) {
                        if(k == 0 || k == (2 * i) - 3) {
                            printf("*");
                        }
                        printf(" ");
                        k++;
                        goto innerLoop2;
                    }
                    k = 0;
                    printf("\n");
                    i++;
                    goto outerLoop;
            }
        }
        else {
            i = 0;
            loop:
                if(i < (2 * value) - 1) {
                    printf("*");
                    i++;
                    goto loop;
                }
        }
        return;
}