#include "binaryNumberChallenge.h"
#include "bitwiseOperators.h"
#include "bitwiseOperatorsChallenge.h"
#include "bitmask.h"
#include "bitmaskChallenge.h"
#include "bitField.h"
#include "bitFieldChallenge.h"

int main(int argc, char **argv) {
    
    //binary number and bits challenge set
    binaryConversion();
    
    //bitwise classes
    printf("\nBitwise Logical Operators\n");
    bitwiseFunc1();
    bitwiseFunc2();
    bitwiseFunc3();
    bitwiseFunc4();
    printf("\nBitwise Shifting Operators\n");
    bitwiseFunc5();
    bitwiseFunc6();
    
    //bitwise challenges
    bitwiseChallengeFunc();
    
    //bitmask classes
    bitmaskClass();

    //bitmask challenge
    bitmaskChallengeFunc();

    //bit field classes
    bitFieldClass();

    //bit field challenge
    bitFieldChallengeFunc();
    
    return 0;
    
}