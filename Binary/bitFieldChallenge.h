#include <stdio.h>

struct box_st {
    unsigned int :4;
    unsigned int fill_style:1;
    unsigned int fill_color:3;
    unsigned int :2;
    unsigned int border_display:1;
    unsigned int border_color:3;
    unsigned int border_style:2;
};

int bitFieldChallengeFunc();
void challenge_bitfield();
void challenge_bitmasks();
void displayBoxBitfield(const struct box_st *box);
void displayBoxBitmask(const unsigned int box);
char *getFillStyle(const unsigned int style);
char *getColor(const unsigned int color);
char *getBorderDisplay(const unsigned int display);
char *getBorderStyle(const unsigned int style);