#include "charChallenge.h"
#include <ctype.h>

static void challenge1(int argc, char **argv);
static void challenge2(int argc, char **argv);

int charChallengeFunc(int argc, char **argv) {
    challenge1(argc, argv);
    challenge2(argc, argv);
    return 0;
}

#define isLetter(c) ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z'))

void challenge1(int argc, char **argv) {
    //count number of words and characters in a file OR from standard input
    //1 command line argument = name of file
    //0 command line argument = stdin
    FILE *fp = NULL;
    char ch = '\0', prevChar = '\0';
    int charCnt = 0;
    int wordCnt = 0;
    
    if(argc == 1)
        fp = stdin;
    else if(argc == 2)
        fp = fopen(argv[1],"r");
    else {
        printf("Incorrect command line arguments\n");
        return;
    }
    
    if(fp == NULL) {
        printf("File not found\n");
        return;
    }
    
    while((ch = getc(fp)) != EOF) {
        //if ch is an upper or lower case letter, increment
        if(isLetter(ch))
            charCnt++;
        //if ch is not an upper nor lower case letter while prevChar is, end of word
        else if(isLetter(prevChar))
                wordCnt++;
        prevChar = ch;
    }
    fclose(fp);
    //print results
    printf("\nThe number of words in the file are: %d\n",wordCnt);
    printf("The number of letters in the file are: %d\n",charCnt);
    
    return;
}

void challenge2(int argc, char **argv) {
    FILE *fpIn = NULL;
    FILE *fpOut = NULL;
    char ch = '\0';
    
    if(argc == 1) {
        fpIn = stdin;
        fpOut = stdout;
    }
    else if(argc == 2) {
        fpIn = fopen(argv[1],"r");
        if(fpIn == NULL) {
            printf("File not found\n");
            return;            
        }
        fpOut = fopen("C:\\Users\\mugiw\\Documents\\Workspaces\\Workspace2\\InputOutput\\charChallenge2Result.txt","w");
        if(fpOut == NULL) {
            printf("File not found\n");
            fclose(fpIn);
            return;
        }
    }
    else {
        printf("Incorrect command line arguments\n");
        return;
    }
    
    while((ch = fgetc(fpIn)) != EOF) {
        if(isupper(ch))
            ch = tolower(ch);
        else if(islower(ch))
            ch = toupper(ch);
        fputc(ch,fpOut);
    }
    fclose(fpIn);
    fclose(fpOut);
    
    return;
}