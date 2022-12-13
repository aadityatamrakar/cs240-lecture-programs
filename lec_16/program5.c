// C program to demonstrate
// example of time() function.
#include <stdio.h>
#include <time.h>

int main()
{
    time_t seconds;

    seconds = time(NULL);

    printf("Seconds since January 1, 1970 = %ld\n", seconds);
    printf("Minutes since January 1, 1970 = %ld\n", seconds / 60);
    printf("Hours since January 1, 1970 = %ld\n", seconds / 3600);
    printf("Days since January 1, 1970 = %ld\n", seconds / 86400);
    printf("Years since January 1, 1970 = %ld\n", seconds / 31536000);
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    
    // localtime() returns a pointer to a tm structure with its members filled with the corresponding values to the time represented in seconds since the Epoch.
    // The tm structure is a type defined in <time.h> as follows:
    // struct tm {
    //     int tm_sec;    // seconds after the minute - [0, 60] including leap second
    //     int tm_min;    // minutes after the hour - [0, 59]
    //     int tm_hour;   // hours since midnight - [0, 23]
    //     int tm_mday;   // day of the month - [1, 31]
    //     int tm_mon;    // months since January - [0, 11]
    //     int tm_year;   // years since 1900
    //     int tm_wday;   // days since Sunday - [0, 6]
    //     int tm_yday;   // days since January 1 - [0, 365]
    //     int tm_isdst;  // daylight savings time flag
    // };
    
    printf("Current time is %d:%d\n", t->tm_hour, t->tm_min);
    printf("Day of the week is %d\n", t->tm_wday);

    printf("Current date and time = %s", ctime(&seconds));

    return (0);
}
