#include "dynamicLib.h"

#include "myDynLib.h"
#include "DynStringFunctions.h"

static void class1();
static void challenge1();

int dynamicLibClass() {
    class1();
    return 0;
}

int dynamicLibChallenge() {
    challenge1();
    return 0;
}

void class1() {
    funDynamic();
    return;
}

void challenge1() {
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
    
    printf("# of '%c' in String 1: %d\n",searchChar,numberOfCharactersInString(str1,searchChar));
    printf("# of '%c' in String 2: %d\n",searchChar,numberOfCharactersInString(str2,searchChar));
    
    if(removeNonAlphaCharacters(str2) == 0)
        printf("Removed non-alphabet characters in String 2: '%s'\n",str2);
    else
        printf("Removal operation failed.\n");
    
    len1 = lengthOfString(str1);
    len2 = lengthOfString(str2);
    printf("Length of String 1: %d\n",len1);
    printf("Length of String 2: %d\n",len2);
    
    if(strConcat(str1, str2) == 0)
        printf("Concatenated strings: '%s'\n",str1);
    else
        printf("Concatenate operation failed.\n");
    
    if(strCopy(str1,str2) == 0)
        printf("Copied string: '%s'\n", str2);
    else
        printf("Copy operation failed.\n");
    
    if(substring(str1,start,count,str3) == 0)
        printf("Substring of '%s' from position %d for %d characters: '%s'\n",str1,start,count,str3);
    else
        printf("Substring operation failed.\n");
        
    return;
}