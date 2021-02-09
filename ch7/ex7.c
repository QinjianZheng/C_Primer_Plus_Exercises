/* 7
编写一个程序，提示用户输入一周工作的小时数，
然后打印工资总额、税金和净收入。

做如下假设:
a.基本工资 = 1000美元/小时 
b.加班(超过40小时) = 1.5倍的时间 
c.税率: 
    前300美元为15% 
    续150美元为20%
    余下的为25%
用#define定义符号常量。不用在意是否符合当前的税法。

*/

#include <stdio.h>
#define BASE 10
#define OVERTIME_HOUR_MUL 1.5
#define NORMAL_HOUR 40
#define FIRST_BUCKET  300
#define SECOND_BUCKET 450
#define RATE_LOWER_THAN_300    0.15
#define RATE_LOWER_THAN_450    0.20
#define RATE_HIGHER_THAN_450   0.25

int main(int argc, char const *argv[])
{
    int hour;
    float sarary;
    float tax;
    printf("Please work hour per week: ");
    scanf("%d", &hour);

    if(hour <= NORMAL_HOUR) {
        sarary = BASE * hour;
    } else {
        sarary = BASE * (NORMAL_HOUR + (hour - NORMAL_HOUR) * OVERTIME_HOUR_MUL);
    }
    if(sarary <= FIRST_BUCKET) {
        tax = sarary * RATE_LOWER_THAN_300;
    } else if(sarary <= SECOND_BUCKET) {
        tax = FIRST_BUCKET * RATE_LOWER_THAN_300 + (sarary - FIRST_BUCKET) * RATE_LOWER_THAN_450;
    } else {
        tax = FIRST_BUCKET * RATE_LOWER_THAN_300 + \
                (SECOND_BUCKET - FIRST_BUCKET) * RATE_LOWER_THAN_450 + \
                (sarary - SECOND_BUCKET) * RATE_HIGHER_THAN_450;
    }

    printf("Total sarary: %.1f\nTotal tax: %.1f\nNet sarary: %1.f\n", sarary, tax, sarary - tax);

    return 0;
}
