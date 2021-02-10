/* 5

编写并测试一个函数larger_of()，该函数把两个double类型变量的值替换为较大的值。
例如， larger_of(x, y)会把x和y中较大的值重新赋给两个变 量。
*/

#include <stdio.h>

void larger_of(double *, double *);


int main(int argc, char const *argv[])
{
    double n1 = 1212.2334;
    double n2 = 5423.12423;
    printf("n1: %lf | n2: %lf\n", n1, n2); 
    larger_of(&n1, &n2);
    printf("n1: %lf | n2: %lf\n", n1, n2); 
    return 0;
}
void larger_of(double *p1, double *p2) {
    if(*p1 > *p2) {
        *p2 = *p1;
    } else {
        *p1 = *p2;
    }
}
