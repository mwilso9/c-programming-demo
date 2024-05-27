#include "stringLecture.h"
#include <string.h>
#include <stdlib.h>

static void class1();
static void class2();
static void class3();


int stringClass() {
    class1();
    class2();
    class3();
    return 0;
}

void class1() {
    char buf[255];
    int ch = '\0';
    char *p = NULL;
    
    if(fgets(buf,sizeof(buf),stdin)){
        p = strchr(buf,'\n');
        if(p)
            *p = '\0';
        else
            while(((ch=getchar())!='\n') && !feof(stdin) && !ferror(stdin));
    }
    else {
        // fgets failed, handle error
    }
    printf("Our buffer contains: %s\n",buf);
    return;
}

void class2() {
    char *buffer = NULL;
    size_t bufsize = 32;
    size_t characters;
    
    buffer = (char *)malloc(bufsize*sizeof(char));
    
    if(buffer == NULL)
        exit(1);
    
    printf("Type something: ");
    characters = getline(&buffer,&bufsize,stdin);
    
    printf("%zu characters were read.\n",characters);
    printf("You type: '%s'\n",buffer);
    
    return;
}

void class3() {
    char str[40];
    strcpy(str,"Hello, how are you?");
    puts(str);
    
    fputs(str,stdout);
    
    return;
}