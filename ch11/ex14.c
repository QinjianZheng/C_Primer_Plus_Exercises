/* 14

编写一个通过命令行运行的程序计算幂。
第1个命令行参数是double 类型的数，作为幂的底数，
第2个参数是整数，作为幂的指数。

*/ 

#include <stdio.h>
#include <stdlib.h>

double power(double, int);

int main(int argc, char const *argv[])
{
    double r = power(atof(argv[1]), atoi(argv[2]));
    printf("%.2lf^%d=%.2lf\n", atof(argv[1]), atoi(argv[2]), r);
    return 0;
}

double power(double base, int exp) {
    if(base == 0) {
        return 0;
    }
    if(exp == 0) {
        return 1;
    } else if(exp < 0) {
        return 1.0/power(base, -exp);
    } else {
        return base * power(base, exp-1);
    }
    
}