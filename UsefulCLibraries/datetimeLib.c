#include "datetimeLib.h"
#include <time.h>
#include <math.h>
#include <ctype.h>

static void class1();
static void class2();
static void class3();

int datetimeLibClass() {
    class1();
    class2();
    class3();
    return 0;
}

void class1() {
    time_t calendar_start = time(NULL);         // Initial calendar time
    clock_t cpu_start = clock();                // Initial processor time
    int count = 0;                              // Count of number of loops
    
    const long long iterations = 1000000000LL;  // Loop iterations
    char answer = 'y';
    double x = 0.0;
    
    printf("Initial clock time = %lld Initial calendar time = %lld\n", (long long) cpu_start, (long long) calendar_start);
    
    while(tolower(answer) == 'y') {
        for(long long i = 0LL; i < iterations; ++i) {
            x = sqrt(3.14159265);
        }
        
        printf("%lld square roots completed.\n",iterations*(++count));
        printf("Do you want to run some more(y or n)?\n");
        scanf("\n%c",&answer);
    }
    
    clock_t cpu_end = clock();                  // Final cpu time
    time_t calendar_end = time(NULL);           // Final calendar time
    x = (double) difftime(calendar_end, calendar_start);
    printf("Final clock time = %lld Final calendar time = %lld\n", (long long) cpu_end, (long long) calendar_end);
    printf("CPU time for %lld iterations is %.2lf seconds\n", count*iterations, ((double) (cpu_end-cpu_start))/CLOCKS_PER_SEC);
    printf("Elapsed calendar time to execture the program is %8.2lf seconds\n", x);
    return;
}

void class2() {
    time_t calendar = time(NULL);
    
    struct tm *time_data;
    const char *days[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    const char *months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    
    time_data = localtime(&calendar);
    
    printf("Today is %s %s %d %d\n", days[time_data->tm_wday], months[time_data->tm_mon], time_data->tm_mday, time_data->tm_year+1900);
    
    return;
}

void class3() {
    const char *day[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    const char *month[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    const char *suffix[] = {"st","nd","rd","th"};
    enum sufindex {st, nd, rd, th} sufsel = th;
    
    struct tm birthday = {0};
    char name[30] = {'\0'};
    /*
    printf("Enter a name: ");
    scanf("%s", name);
    
    printf("Enter the birthday for %s as day month year integers separated by spaces"
            "\ne.g. Enter 1st February 1985 as 1 2 1985 L ",name);
            
    scanf("%d %d %d", &birthday.tm_mday, &birthday.tm_mon, &birthday.tm_year);
    */
    
    sprintf(name,"Matt");
    birthday.tm_mday = 24;
    birthday.tm_mon = 5;
    birthday.tm_year = 1991;
    
    birthday.tm_mon -= 1;
    birthday.tm_year -= 1900;
    
    if(mktime(&birthday) == -1) {
        fprintf(stderr,"Operation failed.\n");
        return;
    }
    switch(birthday.tm_mday) {
        case 1: case 21: case 31:
            sufsel = st;
            break;
        case 2: case 22:
            sufsel = nd;
            break;
        case 3: case 23:
            sufsel = rd;
            break;
        default:
            sufsel = th;
            break;
    }
    
    printf("%s was born on the %d%s %s %d, which was a %s.\n",name,birthday.tm_mday,suffix[sufsel],month[birthday.tm_mon],birthday.tm_year+1900,day[birthday.tm_wday]);
}