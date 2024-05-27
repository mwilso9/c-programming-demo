#ifndef STRINGFUNCTIONS_H_INCLUDED
#define STRINGFUNCTIONS_H_INCLUDED

#ifndef __STDLIB__
#define __STDLIB__
#include <stdlib.h>
#endif // __STDLIB__

int numberOfCharactersInString(char*, char);
int removeNonAlphaCharacters(char*);
int lengthOfString(char*);
int strConcat(char*, char*);
int strCopy(char*, char*);
int substring(char*, int, int, char*);

#endif // STRINGFUNCTIONS_H_INCLUDED