#include "formatting.h"
#include <stdlib.h>
#include <string.h>

static void class1();
static void class2();
static void class3();
static void class4();
static void class5();

/* Will cover:
 *  sprintf -- unsafe, does not check length of destination buffer
 *  fprintf -- same as printf but to a file instead of stdout
 *  fscanf -- same as scanf but from a file instead of stdin
 *  sscan -- same as scanf/fscanf but from a string instead of stdin/file
 *  fflush -- "flushes" the buffer, pushes unwritten data to output buffer and empties buffer
 */

int formattingClass() {
    class1();
    class2();
    class3();
    class4();
    class5();
    return 0;
}

void class1() {
    char string[100];
    int a = 10, b = 20, c = 0;
    c = a+b;
    sprintf(string,"Hello, this is the number: %d",55);
    puts(string);
    
    sprintf(string,"Sum of %d and %d is %d",a,b,c);
    puts(string);
    
    return;
}

void class2() {
    FILE *f = NULL;
    //char ch[100];
    
    f = stdout;
    /* if((f = fopen("data.txt","r+"))==NULL){
        printf("Cannot open the file...\n");
        exit(1);
    }*/
    for(int i = 0; i<10; i++) {
        fprintf(f,"The count number is %d\n",i+1);
    }
    /*fclose(f);
    if((f = fopen("data.txt","r+"))==NULL){
        printf("Cannot open the file...\n");
        exit(1);
    }
    printf("File contrint is--\n");
    printf("\n................print the strings................\n\n");
    while(!feof(f)) {
        fgets(ch,100,f);
        printf("%s",ch);
    }
    fclose(f);
    */
    return;
}

#define MAX 41

void class3() {
    FILE *fp = NULL;
    char buff[255];
    char words[MAX];
    
    //fp = stdin;
    if((fp = fopen("C:\\Users\\mugiw\\Documents\\Workspaces\\Workspace2\\InputOutput\\charChallengeData_Copy.txt","a+")) == NULL) {
        fprintf(stderr,"Error opening file\n");
        return;
    }
    while((fscanf(fp,"%s",buff))!=EOF)
        printf("%s ",buff);
        
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.\n");
    while((fscanf(stdin,"%40s",words) == 1) && (words[0] != '#'))
        fprintf(fp,"%s\n",words);

    puts("File contents:");
    rewind(fp);

    while(fscanf(fp,"%s",words) == 1)
        puts(words);
    puts("Done!");

    if(fclose(fp) != 0)
        fprintf(stderr,"Error closing file\n");
    return;
}

void class4() {
    
    char *str = "Jason Fedin 43";
    char name[10], title[10];
    int age = 0, ret = 0;
    
    ret = sscanf(str,"%s %s %d",name, title, &age);
    if(ret == -1)
        fprintf(stderr,"Error scanning string\n");
    printf("Name: %s\n",name);
    printf("Title: %s\n", title);
    printf("Age: %d\n", age);
    
    return;
}

void class5() {
    return;
}
