/* 1
设计一个函数min(x, y)，返回两个double类型值的较小值。在一个简单
的驱动程序中测试该函数

*/

#include <stdio.h>

double min(double, double);


int main(int argc, char const *argv[])
{
    double x = 1.134;
    double y = 1.212;
    printf("x: %lf | y: %lf | min: %lf\n", x, y, min(x,y));
    return 0;
}

double min(double x, double y) {
    double min = x;
    if(x > y) {
        min = y;
    }
    return min;
}