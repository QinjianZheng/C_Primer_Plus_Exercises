/* 2

两数的调和平均数这样计算:先得到两数的倒数，然后计算两个倒数 的平均值，
最后取计算结果的倒数。
使用#define指令定义一个宏“函数”，执 行该运算。编写一个简单的程序测试该宏。


*/ 

#include <stdio.h>
#define HARMONIC_MEAN(n1, n2) ((1.0/((1.0/n1 + 1.0/n2)/2)))


int main(int argc, char const *argv[])
{
    double x = 5.42;
    double y = 7.21;
    printf("harmonic mean of %.2lf and %.2lf is %.2lf\n", x, y, HARMONIC_MEAN(x,y));
    return 0;
}
