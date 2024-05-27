#include "bitmask.h"

int bitmaskClass() {
    bitmaskFunc1();
    return 0;
}

void bitmaskFunc1() {
    int flags = 15;  //0x0F = 0...0000 1111
    int mask = 182;  //0xB6 = 0...1011 0110
    int result = 0;
    
    printf("--------Bitmask Class-------\n");
    //turn on bits based on a mask using OR
    result = flags | mask; // = 1011 1111
    printf("      %lld\n| %lld\n= %lld\n\n",convertDecToBin(flags),convertDecToBin(mask),convertDecToBin(result));
    
    //turn off bits based on a mask using AND
    result = flags & ~(mask); // = 0000 1001
    printf("       %lld\n& ~%lld\n=      %lld\n\n",convertDecToBin(flags),convertDecToBin(mask),convertDecToBin(result));
    
    //toggle bits based on a mask using XOR
    result = flags ^ mask; // = 1011 1001
    printf("      %lld\n^ %lld\n= %lld\n\n",convertDecToBin(flags),convertDecToBin(mask),convertDecToBin(result));
    
    //check bit
    if((flags & mask) == mask)
        printf("On (all mask bits on)\n");
    else
        printf("Off (not all mask bits on)\n");
    return;
}
