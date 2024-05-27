#include "binaryNumberChallenge.h"

int binaryConversion()
{
    int choice, enteredDecimal;
    ullint enteredBinary;
    
    printf("Binary Conversion: \n");
    while(1) {
        printf("1. Convert Binary to Decimal");
        printf("\n2. Convert Decimal to Binary");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the binary number (up to %d digits): ", MAX_BITS);
                scanf("%llu", &enteredBinary);
                if(validBinEntry(enteredBinary) == FALSE)
                    printf("Invalid binary entry.\n");
                else
                    printf("b%llu = %d\n",enteredBinary,convertBinToDec(enteredBinary));
                break;
                
            case 2:
                printf("Enter the decimal number (between %d and %d): ",(int)(-1*pow(2,MAX_BITS)+1),(int)(pow(2,MAX_BITS)-1));
                scanf("%d", &enteredDecimal);
                if(validDecEntry(enteredDecimal) == FALSE)
                    printf("Invalid decimal entry.\n");
                else
                    printf("%d = b%lld\n",enteredDecimal,convertDecToBin(enteredDecimal));
                break;

            case 0:
                return 0;
            
            default:
                printf("Invalid Choice.\n");
        }
    }    
	return 0;
}

int validBinEntry(ullint val)
{
    int remainder = 0;
    if((val >= 0) && (val < (ullint) pow(10,MAX_BITS))) {
        while(val != 0) {
            remainder = val % 10;
            if((remainder != 0) && (remainder != 1))
                return FALSE;
            val = val / 10;
        }
        return TRUE;
    }
    else
        return FALSE;
}

int validDecEntry(const int val)
{
    if((val > (int) -1*pow(2,MAX_BITS)) && (val < (int) pow(2,MAX_BITS)))
        return TRUE;
    else
        return FALSE;
}

// Challenge #1
int convertBinToDec(ullint bin)
{

    unsigned int sign = bin/pow(10,MAX_BITS-1);
    int i, convertedValue = 0/*, calcVal = 0*/;
    int remainder = 0;
    
/*    if(sign == 0) {
        for(i = MAX_BITS-1; i >= 0; i--) {
            calcVal = (bin/(int)pow(10,i));
            if(calcVal == 1) {
                convertedValue += pow(2,i);
                bin -= calcVal*pow(10,i);
            }
        }

    }
    else if(sign == 1) {
        for(i = MAX_BITS-1; i >= 0; i--) {
            calcVal = (bin/(int)pow(10,i));
            if(calcVal == 0)
                convertedValue += pow(2,i);
            else
                bin -= calcVal*pow(10,i);
        }
        convertedValue += 1;
        convertedValue *= -1;

    }
    else
        printf("Error occurred\n");
*/
    for(i = 0; (i < MAX_BITS) && (bin != 0); i++) {
        remainder = bin % 10;
        if(((sign == 0) && (remainder == 1)) ||
            ((sign == 1) && (remainder == 0)))
                convertedValue += (int)pow(2,(double)i);
        bin = bin / 10;
    }
    if(sign == 1) {
        convertedValue += 1;
        convertedValue *= -1;       
    }

    return convertedValue;
}

// Challenge #2
ullint convertDecToBin(int dec)
{
    int i;
    ullint convertedValue = 0;
    int /*calcVal = 0,*/ neg = FALSE;
    int remainder = 0;
    
    if(dec < 0) {
        neg = TRUE;
        dec *= -1;
        dec -= 1;
        convertedValue += pow(10,MAX_BITS-1);
    }
/*    for(i = MAX_BITS-2; i >= 0; i--) {
        calcVal = pow(2,i);
        if(dec >= calcVal) {
            if(neg == FALSE)
                convertedValue += (ullint) pow(10,i);
            dec -= calcVal;
        }
        else if((neg == TRUE) && (dec < calcVal))
            convertedValue += (ullint) pow(10,i);
    }
*/
    for(i = 0; i < MAX_BITS-1; i++) {
        remainder = dec % 2;
        if(((neg == FALSE) && (remainder == 1)) ||
            ((neg == TRUE) && (remainder == 0)))
                convertedValue += (ullint) pow(10,(double)i);
        dec = dec / 2;
    }
    return convertedValue;
}