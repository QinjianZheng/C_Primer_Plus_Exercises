/* 1

重新编写复习题 5，用月份名的拼写代替月份号(别忘了使用strcmp())。
在一个简单的程序中测试该函数。

复习题5
编写一个函数，用户提供月份号，该函数就返回一年中到该月为止(包括该月)的总天数。
假设在所有函数的外部声明了第3题的结构模版和一个该类型结构的数组。

*/ 

#include <stdio.h>
#include <string.h>

#define MONTHS  12
#define SIZE    4   // 
int countDayToMonth(int month);
int countDayToMonthStr(char *month);
enum MONTH_DAY {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char monthStr[MONTHS][SIZE] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", 
                          "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

int main(int argc, char const *argv[])
{
    int month;
    char monthStr[SIZE];
    do {
        printf("Please enter the number for month: ");
        scanf("%d", &month);
        printf("There are %d days to month %d from beginning of the year.\n", 
                countDayToMonth(month), month);
        printf("Please enter the capital abbreviation of word for month");
        printf("(e.g. JAN for January, FEB for February...\n");
        scanf("%s", monthStr);
        printf("There are %d days to %s from beginning of the year.\n", 
                countDayToMonthStr(monthStr), monthStr);
    } while(strcmp(monthStr, "#") != 0);
    return 0;
}

int countDayToMonth(int month) {
    
    int dayCount = 0;
    
    for(int i = 0; i < month; i++) {
        dayCount += days[i];
    }
    return dayCount;
}

int countDayToMonthStr(char *month) {
    int dayCount = 0;
    enum MONTH_DAY monthDay;

    for(monthDay = JAN; monthDay <= DEC; monthDay ++) {
        
        if(strcmp(month, monthStr[monthDay]) == 0) {
            dayCount += days[monthDay];
            break;
        } else {
            dayCount += days[monthDay];
        }
    }
    return dayCount;
}
