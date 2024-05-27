#include "date.h"

// function to calculate tomorrow's date
Date dateUpdate(Date today)
{
    Date tomorrow;
    
    if(today.day!=numberOfDays(today)) // not the end of month
        setDay(tomorrow,today.month,today.day+1,today.year);
    else if(today.month == December) // end of year
        setDay(tomorrow,January,1,today.year+1);
    else // end of month
        setDay(tomorrow,today.month+1,1,today.year);
        
    return tomorrow;
}

// function to get number of days in month of date
int numberOfDays (Date d)
{
    switch(d.month)
    {
        case January:
        case March:
        case May:
        case July:
        case August:
        case October:
        case December:
            return 31;
        case April:
        case June:
        case September:
        case November:
            return 30;
        case February:
            return (isLeapYear(d) ? 29 : 28);
        default:
            return 0; // error
    }
}

// function to determine if is a leap year
bool isLeapYear (Date d)
{
    if(d.year % 4 == 0)
        return true;
    else
        return false;
}

int main(int argc, char **argv)
{
    int ch, end_day;
    Date entered_date,tomorrow_date;
    setDay(entered_date,1,1,1);
    while(1) {
        printf("Enter current date. \n");
        //get year
        printf("Enter year(-1 to exit): ");
        scanf("%d", &ch);
        entered_date.year = ch;
        if(ch == -1) break;
        //get month
        printf("\nEnter Month(1-12, -1 to exit): ");
        scanf("%d", &ch);

        while(ch < 1 || ch > 12)
        {
            if(ch == -1)
            {
                printf("Exiting...");
                return 0;
            }
            printf("Invalid value.\nEnter Month(1-12, -1 to exit): ");
            scanf("%d", &ch);
        }
        entered_date.month = ch;
        //get day
        end_day = numberOfDays(entered_date);
        printf("\nEnter Day(1-%d, -1 to exit): ",end_day);
        scanf("%d", &ch);
        while(ch < 1 || ch > end_day)
        {
            if(ch == -1)
            {
                printf("Exiting...");
                return 0;
            }            printf("Invalid value.\nEnter Day(1-%d, -1 to exit): ",end_day);
            scanf("%d", &ch);
        }
        entered_date.day = ch;
        //return tomorrow
        tomorrow_date=dateUpdate(entered_date);
        printf("Tomorrow is %d-%d-%d.\n",tomorrow_date.month,tomorrow_date.day,tomorrow_date.year);
    }
    printf("Exiting...");
	return 0;
}