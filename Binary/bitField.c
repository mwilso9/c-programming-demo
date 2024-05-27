#include "bitField.h"

struct packed_st {
    int count;
    char c;
    unsigned int :3; //padding
    unsigned int flag1:1;
    unsigned int flag2:1;
    unsigned int flag3:1;
    unsigned int type:8;
    unsigned int index:18;
};

int bitFieldClass() {
    bitFieldFunc1();
    return 0;
}

void bitFieldFunc1() {
    struct packed_st packed_data = {1, 'A', 1, 0, 0, 5, 255};
    
    packed_data.type = 7;
    printf("Type = %u\n",packed_data.type);
/*    packed_data.type = 256;
    printf("Type = %u\n",packed_data.type);
    
    unsigned int bit = packed_data.type;
    
    unsigned int i = packed_data.index / 5 + 1;
    
    if(packed_data.flag2)
    {
        
    }
 */   
    return;
}