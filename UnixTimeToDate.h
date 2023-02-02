#include <time.h> 
void convertUnixTimeToDate(time_t t, int *sec, int *m, int *h, int *day, int *month, int *year)
 {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int f;
  
    //Negative Unix time values are not supported
    if(t < 1)
       t = 0;
  
    //Retrieve hours, minutes and seconds
    *sec = t % 60;
    t /= 60;
    *m = t % 60;
    t /= 60;
    *h = t % 24;
    t /= 24;
  
    //Convert Unix time to date
    a = (unsigned) ((4 * t + 102032) / 146097 + 15);
    b = (unsigned) (t + 2442113 + a - (a / 4));
    c = (20 * b - 2442) / 7305;
    d = b - 365 * c - (c / 4);
    e = d * 1000 / 30601;
    f = d - e * 30 - e * 601 / 1000;
  
    //January and February are counted as months 13 and 14 of the previous year
    if(e <= 13)
    {
       c -= 4716;
       e -= 1;
    }
    else
    {
       c -= 4715;
       e -= 13;
    }
  
    //Retrieve year, month and day
    *year = c;
    *month = e;
    *day = f;
  
 }
