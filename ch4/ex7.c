/* 7

编写一个程序，将一个double类型的变量设置为1.0/3.0，
一个float类 型的变量设置为1.0/3.0。
分别显示两次计算的结果各3次:
一次显示小数点后面6位数字;
一次显示小数点后面12位数字;
一次显示小数点后面16位数字。

程序中要包含float.h头文件，并显示FLT_DIG和DBL_DIG的值。
1.0/3.0 的值与这些值一致吗?

*/

#include <stdio.h>
#include <float.h>


int main(int argc, char const *argv[])
{
    printf("FLT DIG: %d\n", FLT_DIG);
    printf("DBL DIG: %d\n", DBL_DIG);

    double d = 1.0/3.0;
    float f = 1.0/3.0;

    printf("decimal digit 6: double %.6f | float %.6f\n", d, f);
    printf("decimal digit 12: double %.12f | float %.12f\n", d, f);
    printf("decimal digit 16: double %.16f | float %.16f\n", d, f);
    


    return 0;
}
