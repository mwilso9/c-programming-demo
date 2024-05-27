#include "char.h"

static void class1();
static void class2();
static int class3();
static void class4();
static void class5();
static void class6();
static void class7();

int charClass() {
    class1();
    class2();
    class3();
    class4();
    class5();
    class6();
    class7();
    return 0;
}

void class1() {
    //int getc(FILE *stream)
    //read single character from stream
    char ch = '\0';
    /* FILE *fp;
    if((fp = fopen("someFile.c","rw"))) {
        ch = getc(fp);
        while(ch != EOF)
        {
            ch = getc(fp);
        }
        fclose(fp);
    } */
    ch = getc(stdin);
    printf("read in character %c\n",ch);

    return;
}

void class2() {
    //int getchar(void)
    //read single character from terminal
    int cha = 0;
    while((cha=getchar()) != EOF) {
        printf("%c\n",cha);
    }
    return;
}

int class3() {
//int fgetc(FILE *stream);
    // FILE *fp = NULL;
    char c = '\0';
    FILE *fp;
    fp = fopen("myFile.c","r");
    
    if(fp == NULL) {
        printf("Could not open file myFile.c");
        return 1;
    }
    printf("Reading the file myFile.c");
    while(1) {
        c = fgetc(fp);
        if(c==EOF)
            break;
        printf("%c",c);
    }
    printf("Closing the file test.c");
    fclose(fp);
    return 0;
}

void class4() {
    //int ungetc(int ch, FILE* stream);
    char ch2 = 0;
    //while(isspace(ch2=(char)getchar()));
    ungetc(ch2,stdin); //puts char back in input file/stream
    printf("char is %c\n",getchar());
    return;
}

void class5() {
    //int putc(int char, FILE* fp);
    char ch = 'd';
/*    FILE *fp = NULL;
    putc('\n',stdout);
    
    if(fp=fopen("someFile.c","rw") {
        ch = getc(fp);
        while(ch != EOF) {
            putc(ch,fp);
            ch = get(fp);
        }
    } */
    putc(ch,stdout);
    
    return;
}

void class6() {
    //int putchar();
    char string[] = "Hello Jason, \nwhatever!";
    int i = 0;
    while(string[i] != '\0') {
        if(string[i] != '\n')
            putchar(string[i]);
        ++i;
    }
    return;
}

void class7() {
    //int fputc(int ch, FILE *stream);
    //FILE *pfile;
    char c;
    
    //pfile = fopen("myFile.txt","w");
    //if(pfile != NULL) {
        for(c='A';c<='Z';c++)
            //fputc(c,pfile);
            fputc(c,stdout);
     //   fclose(pfile);
    //}
    
    return;
}