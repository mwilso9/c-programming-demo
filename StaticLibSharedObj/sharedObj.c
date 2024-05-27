#include "sharedObj.h"

static void class1();
static void challenge1();

int sharedObjClass() {
    class1();
    return 0;
}

int sharedObjChallenge() {
    challenge1();
    return 0;
}

void class1() {
    void *handle = NULL;
    double (*cosine) (double) = NULL;
    char *err = NULL;
    
    handle = dlopen("/usr/bin/cygwin1.dll",RTLD_LAZY);
    
    if(handle == NULL) {
        fputs(dlerror(),stderr);
        exit(1);
    }
    dlerror();
    
    cosine = dlsym(handle,"cos");
    if((err=dlerror()) != NULL) {
        fputs(err,stderr);
        exit(2);
    }
    
    printf("cos(%.1f) = %f\n",2.0,(*cosine)(2.0));
    
    dlclose(handle);
    
    return;
}

void challenge1() {
    
    void *handle = NULL;
    char *err = NULL;
    int (*stringCharCount)(char*, char) = NULL;
    int (*removeNonAlphaChar)(char*) = NULL;
    int (*stringLength)(char*) = NULL;
    int (*concatString)(char*, char*) = NULL;
    int (*copyString)(char*, char*) = NULL;
    int (*getSubstring)(char*, int, int, char*) = NULL;
    
    handle = dlopen("C:/Users/mugiw/Documents/Workspaces/Workspace2/myDynamicLibrary/lib_myStringFunc.dll",RTLD_LAZY);
    
    if(handle == NULL) {
        fputs(dlerror(),stderr);
        exit(1);
    }
    dlerror();
    
    char str1[255] = "Hello ";
    char str2[255] = "L33+ World!";
    str1[6] = '\0';
    str2[11] = '\0';
    char str3[255] = {'\0'};
    char searchChar = 'l';
    int len1 = 0;
    int len2 = 0;
    int start = 3;
    int count = 6;
    
    printf("String 1: '%s'\n",str1);
    printf("String 2: '%s'\n",str2);
    
    stringCharCount = dlsym(handle,"numberOfCharactersInString");
    if((err=dlerror()) != NULL) {
        fputs(err,stderr);
        exit(2);
    }
    printf("# of '%c' in String 1: %d\n",searchChar,stringCharCount(str1,searchChar));
    printf("# of '%c' in String 2: %d\n",searchChar,stringCharCount(str2,searchChar));
    
    removeNonAlphaChar = dlsym(handle,"removeNonAlphaCharacters");
    if((err=dlerror()) != NULL) {
        fputs(err,stderr);
        exit(3);
    }
    if(removeNonAlphaChar(str2) == 0)
        printf("Removed non-alphabet characters in String 2: '%s'\n",str2);
    else
        printf("Removal operation failed.\n");

    stringLength = dlsym(handle,"lengthOfString");
    if((err=dlerror()) != NULL) {
        fputs(err,stderr);
        exit(4);
    }    
    len1 = stringLength(str1);
    len2 = stringLength(str2);
    printf("Length of String 1: %d\n",len1);
    printf("Length of String 2: %d\n",len2);
    
    concatString = dlsym(handle,"strConcat");
    if((err=dlerror()) != NULL) {
        fputs(err,stderr);
        exit(5);
    }
    if(concatString(str1, str2) == 0)
        printf("Concatenated strings: '%s'\n",str1);
    else
        printf("Concatenate operation failed.\n");
    
    copyString = dlsym(handle,"strCopy");
    if((err=dlerror()) != NULL) {
        fputs(err,stderr);
        exit(6);
    }
    if(copyString(str1,str2) == 0)
        printf("Copied string: '%s'\n", str2);
    else
        printf("Copy operation failed.\n");
    
    getSubstring = dlsym(handle,"substring");
    if((err=dlerror()) != NULL) {
        fputs(err,stderr);
        exit(7);
    }
    if(getSubstring(str1,start,count,str3) == 0)
        printf("Substring of '%s' from position %d for %d characters: '%s'\n",str1,start,count,str3);
    else
        printf("Substring operation failed.\n");
    
    dlclose(handle);
    return;
}