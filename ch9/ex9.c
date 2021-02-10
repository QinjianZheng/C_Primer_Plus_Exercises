/* 9

使用递归函数重写编程练习8。
*/

#include <stdio.h>

double power(double n, int p); // ANSI函数原型

int main(void)
{
    double x, xpow;
    int exp; 
    printf("Enter a number and the positive integer power"); 
    printf(" to which\nthe number will be raised. Enter q"); 
    printf(" to quit.\n"); 
    while (scanf("%lf%d", &x, &exp) == 2) {
        xpow = power(x, exp); // 函数调用 
        printf("%.3g to the power %d is %.5g\n", x, exp, xpow); 
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip -- bye!\n"); 
    return 0;
}

double power(double n, int p)  {// 函数定义 
    if(n == 0) {
        return 0;
    }
    if(p == 0) {
        return 1;
    } 
    if(p < 0) {
        return 1.0/power(n, -p);
    }
    return n*power(n, p-1);

}