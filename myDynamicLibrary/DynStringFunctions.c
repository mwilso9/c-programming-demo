#include "DynStringFunctions.h"

#define MAX_LENGTH 255 //used to avoid infinite loops

/* Find the frequency of characters in a string
 * str - string to search
 * searchCharacter - character to look for
 * return type - int: count for the number of times that character was found
*/
int numberOfCharactersInString(char *str, char searchCharacter) {
    int charCnt = 0;

    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == searchCharacter)
            charCnt++;
    }
    
    return charCnt;
}

/* Remove all characters in a String except Alphabets
 * source - source string
 * return type - int: 0 on success
*/
#define isLowerAlphabet(c) ((c >= 'a') && (c <= 'z'))
#define isUpperAlphabet(c) ((c >= 'A') && (c <= 'Z'))

int removeNonAlphaCharacters(char *source) {
    int i = 0, j = 0;

    while(source[i] != '\0') {
        while(!(isLowerAlphabet(source[i]) || isUpperAlphabet(source[i]) || source[i] == '\0')) {
            for(j = i; source[j] != '\0'; j++) {
                source[j] = source[j+1];
            }
            source[j] = '\0';
        }
        i++;
    }
    source[i] = '\0';

    return 0;
}

/* Calculate the length of a string without using strlen
 * source - source string
 * return type - int: length of string
*/
int lengthOfString(char *source) {
    int charCnt = 0;

    while(source[charCnt] != '\0') {
        charCnt++;
        if(charCnt >= MAX_LENGTH) {
            return -1;
        }
    }
    
    return charCnt;
}

/* Concatenate two strings without using strcat
 * str1 - string to concatenate to (resulting string)
 * str2 - second string to concatenate from
 * return type - int: 0 on success
*/
int strConcat(char *str1, char *str2) {
    int str1length = lengthOfString(str1);
    int str2length = lengthOfString(str2);
    int i, j;
    
    for(i = str1length, j = 0; j <= str2length; i++, j++) {
        str1[i] = str2[j];
    } 
    
    return 0;
}

/* Copy a string manually without using strcpy
 * source - string to copy from
 * destination - second string to copy to
 * return type - int: 0 on success
*/
int strCopy(char *source, char *destination) {
    int i = 0;
    for(i = 0; source[i] != '\0'; i++) {
        destination[i] = source[i];
    } 
    destination[i] = '\0';
    
    return 0;
}

/* Find the substring of a given string
 * source - source string
 * from - starting index from where you want to get substring
 * n - number of characters to be copied in substring
 * target - target string in which you want to store target string
 * return type - int: 0 on success
*/
int substring(char *source, int from, int n, char *target) {
    int srclength = lengthOfString(source);
    int i = 0;
    
    if(from+n > srclength)
        return -1;
    
    while(i < n) {
        target[i] = source[i+from];
        i++;
    }
    target[i] = '\0';
    
    return 0;
}