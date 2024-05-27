#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
//enumerations
enum kMonth { January=1,February,March,April,May,June,
    July,August,September,October,November,December };

enum kDay { Sunday,Monday,Tuesday,Wednesday,Thursday,
    Friday,Saturday };
//date strcut
struct date
{
    enum    kMonth  month;
    enum    kDay    day;
    int             year;
};
//Date type
typedef struct date Date;
//functions that work with dates
Date dateUpdate (Date today);
int numberOfDays (Date d);
bool isLeapYear (Date d);
//macro to set date in structure
#define setDay(s,mm,dd,yy) s=(Date){mm,dd,yy}
//external variable reference
extern Date todaysDate;


#endif