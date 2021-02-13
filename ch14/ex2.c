/* 2
编写一个函数，提示用户输入日、月和年。
月份可以是月份号、月份名或月份名缩写。
然后该程序应返回一年中到用户指定日子(包括这一天)的总天数。

*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MONTHS  13

void getInfo(int *year, int *month, int *day);
int countDayToDate(int year, int month, int day);
bool isLeap(int year);
int days[MONTHS] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
enum MONTH_DAY {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

int main(int argc, char const *argv[])
{
    int day, month, year;
    getInfo(&year, &month, &day);
    while(1) {
        if(month == FEB && !isLeap(year) && day == 29) {
            printf("There is no this day in year %d\n", year);
        } else {
            printf("There are %d days to %d-%d-%d from beginning of the year.\n", 
                countDayToDate(year, month, day), year, month, day);
        }
        getInfo(&year, &month, &day);
    }
    return 0;
}

//(1) 被4整除且不被100整除 或
//(2) 被400整除
bool isLeap(int year) {
    return ( !(year % 4) && (year % 100) ) || !(year % 400);
}

int countDayToDate(int year, int month, int day) {
    enum MONTH_DAY monthDay;
    int dayCount = 0;

    for(monthDay = JAN; monthDay < month; monthDay++) {
        if(monthDay == FEB && isLeap(year)) {
            dayCount += days[FEB]+1;
        } else {
            dayCount += days[monthDay];
        }
        
    }
    dayCount += day;
    return dayCount;
}

void getInfo(int *year, int *month, int *day) {
    
    printf("Please enter the number for year (e.g. 2000): ");
    if(scanf("%d", year) != 1 || *year < 0) {
        exit(1);
    }
    printf("Please enter the number for month: ");
    if(scanf("%d", month) != 1 || *month < 0) {
        exit(1);
    }
    printf("Please enter the day of the month: ");
    if(scanf("%d", day) != 1 || *day < 0) {
        exit(1);
    }
}
