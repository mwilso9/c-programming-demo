#include "bitwiseOperators.h"

int bitwiseFunc1(void) {
    short int w1 = 25;
    short int w2 = 77;
    short int w3 = 0;
    short int w4 = 0;
    
    w3 = w1 & w2;
    //25 = 0x0019 = 0000 0000 0001 1001
    //77 = 0x004D = 0000 0000 0100 1101
    // & =        = 0000 0000 0000 1001 = 9
    
    w4 = w1 & 3; // last two bits of w1
    
    printf("%d & %d = %d\n",w1,w2,w3);
    printf("%d & 3 = %d\n",w1,w4);
    
    return 0;
}

int bitwiseFunc2(void) {
    short int w1 = 147;
    short int w2 = 61;
    short int w3 = 0;
    
    w3 = w1 | w2;
    //147 = 0x0093 = 0000 0000 1001 0011
    // 61 = 0x003D = 0000 0000 0011 1101
    //  | =        = 0000 0000 1011 1111 = 191
    
    printf("%d | %d = %d\n",w1,w2,w3);
    
    return 0;
}

int bitwiseFunc3(void) {
    short int w1 = 147;
    short int w2 = 61;
    short int w3 = 0;
    short int temp = 0;
    
    w3 = w1 ^ w2;
    //147 = 0x0093 = 0000 0000 1001 0011
    // 61 = 0x003D = 0000 0000 0011 1101
    //  ^ =        = 0000 0000 1010 1110 = 174
    
    printf("%d ^ %d = %d\n",w1,w2,w3);
    
    //example swapping values between variables without a 3rd temp variable using xor
    printf("Before var swap\tw1 = %d, w2 = %d\n",w1,w2);
    temp = w1;
    w1 = w2;
    w2 = temp;
    printf("After var swap\tw1 = %d, w2 = %d\n",w1,w2);
    
    printf("Before xor swap\tw1 = %d, w2 = %d\n",w1,w2);
    w1 ^= w2;
    w2 ^= w1;
    w1 ^= w2;
    printf("After xor swap\tw1 = %d, w2 = %d\n",w1,w2);

    return 0;
}

int bitwiseFunc4(void) {
    short int w1 = 2;
    short int w2 = 154;
    short int result = 0;
    
    result = ~w1;
    //2 = 0x0002 = 0000 0000 0000 0010
    //~ =        = 1111 1111 1111 1101 = -3
    
    printf("~%d = %d\n",w1,result);

    result = ~w2;
    //154 = 0x009A = 0000 0000 1001 1010
    //  ~ =        = 1111 1111 0110 0101 = -155
    
    printf("~%d = %d\n",w2,result);
    
    return 0;
}

int bitwiseFunc5(void) {
    int i = 1;    //0x00000001
    int w1 = 3;   //0x00000003
    int w2 = 138; //0x0000008A
    int result = 0;
    
    i++; //just to avoid unused warning
    
    result = w1 << 1; // same as w1*pow(2,1)
    // 3   = 0x0003 = 0000 0000 0000 0011
    //<< 1 =        = 0000 0000 0000 0110 = 6
    
    printf("%d << 1 = %d\n",w1,result);
    
    result = w2 << 2; // same as w1*pow(2,2)
    //138   = 0x008A = 0000 0000 1000 1010
    // << 2 =        = 0000 0100 0011 0000 = 138*4 = 552
    
    printf("%d << 2 = %d\n",w2,result);
    
    return 0;
}

int bitwiseFunc6(void) {
    unsigned int w1 = 4151832098; // 0xF777EE22
    signed int w2 = 4151832098; //
    int result = 0;
    
    result = w1 >> 1;// same as w1/pow(2,1)
    //4151832098 = 0xF777EE22 = 1111 0111 0111 0111 1110 1110 0010 0010
    //      >> 1 =            = 0111 1011 1011 1011 1111 0111 0001 0001 = 2075916049
    
    printf("%u >> 1 = %u\n",w1,result);
    
    result = w2 >> 2; //different now using negative values
    //4151832098 = 0xF777EE22 = 1111 0111 0111 0111 1110 1110 0010 0010
    //      >> 2 =            = 1111 1011 1011 1011 1111 0111 0001 0001
    
    printf("%d >> 2 = %d\n",w2,result);
    
    return 0;
}