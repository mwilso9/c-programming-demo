#ifndef __STDIO__
#include <stdio.h>
#define __STDIO__
#endif

#ifndef __MATH__
#include <math.h>
#define __MATH__
#endif

#define MAX_BYTES 2
#define BITS_PER_BYTE 8
#define MAX_BITS BITS_PER_BYTE*MAX_BYTES
#define TRUE 1
#define FALSE 0

typedef unsigned long long int ullint;

int binaryConversion();
int convertBinToDec(ullint bin);
ullint convertDecToBin(int dec);
int validBinEntry(ullint value);
int validDecEntry(const int value);