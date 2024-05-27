#include "stringChallenge.h"
#include <string.h>
#include <stdlib.h>

static void challenge1(int argc, char** argv);

int stringChallengeFunc(int argc, char** argv) {
    challenge1(argc,argv);
    return 0;
}

void challenge1(int argc, char** argv) {
    //1st argument is character
    //2nd argument is filename
    //print only those lines in the file containing the given character
    FILE *fpIn = NULL;
    FILE *fpOut = stdout;
    char ch = '\0';
    char *buffer = NULL;
    size_t bufsize = 256;
    
    if(argc != 3) {
        printf("Incorrect command line arguments\nUsage: %s character filename\n",argv[0]);
        return;
    }

    if(strlen(argv[1]) > 1) {
        printf("Invalid character '%s'\nUsage: %s character filename\n",argv[1],argv[0]);
        return;
    }
    ch = argv[1][0];
    
    if((fpIn = fopen(argv[2],"r")) == NULL) {
        printf("File '%s' not found\nUsage: %s character filename\n",argv[2],argv[0]);
        return;
    }

    if((buffer = (char *)malloc(bufsize*sizeof(char))) == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    while(getline(&buffer,&bufsize,fpIn) >= 0) {
        //if ch exists in buffer, print line
        if(strchr(buffer,ch) != NULL)
            fputs(buffer,fpOut);
    }
    fclose(fpIn);
    free(buffer);

    return;
}