/* 12

重写程序清单10.7的rain.c程序，把main()中的主要任务都改成用函数来完成。
*/

#include <stdio.h>
#define MONTHS 12   // 一年的月份数 
#define YEARS  5    // 年数 

float subtotalMonth(int, const float [][MONTHS]);
float subtotalYear(int, const float [YEARS][MONTHS]);

int main(void) {
// 用2010~2014年的降水量数据初始化数组
    const float rain[YEARS][MONTHS] =
    {
    { 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5,  6.6 },
    { 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4,  7.3 },
    { 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1,  8.4 },
    { 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3,  6.2 },
    { 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6,  5.2 }
    };
    int year, month;
    float subtot, total;
    printf(" YEAR   RAINFALL  (inches)\n");

    
    for (year = 0, total = 0; year < YEARS; year++) {             // 每一年，各月的降水量总和 
        subtot = subtotalMonth(year, rain);
        printf("%5d %15.1f\n", 2010 + year, subtot);
        
        total += subtot;  // 5年的总降水量
    }
    printf("\nThe yearly average is %.1f inches.\n\n", total /  YEARS);
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep Oct ");
    printf(" Nov  Dec\n"); 
    for (month = 0; month < MONTHS; month++) {             // 每个月，5年的总降水量 
        subtot = subtotalYear(month, rain);
        printf("%4.1f ", subtot / YEARS);
    }
    printf("\n");
    return 0;
}

float subtotalMonth(int year, const float rain[][MONTHS]) {
    float subtotal = 0;
    for(int i = 0; i < MONTHS; i++) {
        subtotal += rain[year][i];
    }
    return subtotal;
}
float subtotalYear(int month, const float rain[YEARS][MONTHS]) {
    float subtotal = 0;
    for(int i = 0; i < YEARS; i++) {
        subtotal += rain[i][month];
    }
    return subtotal;
}
