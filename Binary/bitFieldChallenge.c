#include "bitFieldChallenge.h"

#define FILL_PADDING_BITS 12     //byte 1 bits 7-4
#define FILL_STYLE_BIT 11        //byte 1 bit 3
#define FILL_COLOR_BITS 8       //byte 1 bits 2-0
#define BORDER_PADDING_BITS 6   //byte 2 bits 7-6
#define BORDER_DISPLAY_BIT 5    //byte 2 bit 5
#define BORDER_COLOR_BITS 2     //byte 2 bits 4-2
#define BORDER_STYLE_BITS 0     //byte 2 bits 1-0

//fill styles
#define TRANSPARENT 0
#define OPAQUE 1
//fill or border colors, rgb representation (3 bits = BGR)
#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7
//border displayed
#define HIDDEN 0
#define SHOWN 1
//border line style
#define SOLID 0
#define DOTTED 1
#define DASHED 2
//bit masks
#define FILL_STYLE_MASK 1 << FILL_STYLE_BIT
#define FILL_COLOR_MASK 7 << FILL_COLOR_BITS
#define BORDER_DISPLAY_MASK 1 << BORDER_DISPLAY_BIT
#define BORDER_COLOR_MASK 7 << BORDER_COLOR_BITS
#define BORDER_STYLE_MASK 3 << BORDER_STYLE_BITS
    
int bitFieldChallengeFunc() {
    printf("--------Bit Fields--------\n");
    challenge_bitfield();
    printf("\n--------Bit Masks---------\n");
    challenge_bitmasks();
    return 0;
}

void challenge_bitfield() {
    struct box_st box_bitfield = {OPAQUE,YELLOW,SHOWN,GREEN,DASHED};
    printf("Original box settings:\n");
    displayBoxBitfield(&box_bitfield);
    
    box_bitfield.fill_style = TRANSPARENT;
    box_bitfield.fill_color = WHITE;
    box_bitfield.border_display = SHOWN;
    box_bitfield.border_color = MAGENTA;
    box_bitfield.border_style = SOLID;
    
    printf("\nModified bos settings:\n");
    displayBoxBitfield(&box_bitfield);
    
    return;
}

void challenge_bitmasks() {
    unsigned int box_bitmask = 0;
    printf("Original box settings:\n");
    displayBoxBitmask(box_bitmask);
    
    box_bitmask |= TRANSPARENT << FILL_STYLE_BIT;
    box_bitmask |= WHITE << FILL_COLOR_BITS;
    box_bitmask |= SHOWN << BORDER_DISPLAY_BIT;
    box_bitmask |= MAGENTA << BORDER_COLOR_BITS;
    box_bitmask |= SOLID << BORDER_STYLE_BITS;

    printf("\nModified bos settings:\n");
    displayBoxBitmask(box_bitmask);
    
    return;
}

void displayBoxBitfield(const struct box_st *box) {
    printf("Box is %s.\n", getFillStyle(box->fill_style));
    printf("The fill color is %s.\n", getColor(box->fill_color));
    printf("Border %s.\n", getBorderDisplay(box->border_display));
    printf("The border color is %s.\n", getColor(box->border_color));
    printf("The border style is %s.\n", getBorderStyle(box->border_style));
}

void displayBoxBitmask(const unsigned int box) {
    printf("Box is %s.\n", getFillStyle((box & FILL_STYLE_MASK)>>FILL_STYLE_BIT));
    printf("The fill color is %s.\n", getColor((box & FILL_COLOR_MASK)>>FILL_COLOR_BITS));
    printf("Border %s.\n", getBorderDisplay((box & BORDER_DISPLAY_MASK)>>BORDER_DISPLAY_BIT));
    printf("The border color is %s.\n", getColor((box & BORDER_COLOR_MASK)>>BORDER_COLOR_BITS));
    printf("The border style is %s.\n", getBorderStyle((box & BORDER_STYLE_MASK)>>BORDER_STYLE_BITS));
}

char *getFillStyle(const unsigned int style) {

    switch(style) {
        case TRANSPARENT:
            return "transparent";
        case OPAQUE:
            return "opaque";
        default:
            return "ERROR";
    }
}

char *getColor(const unsigned int color) {
    switch(color) {
        case BLACK:
            return "black";
        case RED:
            return "red";
        case GREEN:
            return "green";
        case YELLOW:
            return "yellow";
        case BLUE:
            return "blue";
        case MAGENTA:
            return "magenta";
        case CYAN:
            return "cyan";
        case WHITE:
            return "white";
        default:
            return "ERROR";
    }
}

char *getBorderDisplay(const unsigned int display) {
    switch(display) {
        case HIDDEN:
            return "hidden";
        case SHOWN:
            return "shown";
        default:
            return "ERROR";
    }
}

char *getBorderStyle(const unsigned int style) {
    switch(style) {
        case SOLID:
            return "solid";
            break;
        case DOTTED:
            return "dotted";
            break;
        case DASHED:
            return "dashed";
            break;
        default:
            return "ERROR";
    }
}

/*
 * 0000 0011
 * 1111 1100 = 0xFD 15*16+12 = 252 
*/