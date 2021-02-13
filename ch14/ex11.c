/* 11

编写一个名为transform()的函数，接受4个参数:
内含double类型数据的源数组名、
内含double类型数据的目标数组名、
一个表示数组元素个数的int类型参数、
函数名(或等价的函数指针)。
transform()函数应把指定函数应用于源数组中的每个元素，
并把返回值储存在目标数组中。
例如:
transform(source, target, 100, sin);
该声明会把target[0]设置为sin(source[0])，等等，共有100个元素。
在一个程序中调用transform()4次，以测试该函数。

分别使用math.h函数库中的两个函数以及自定义的两个函数作为参数。

*/ 

#include <stdio.h>
#include <math.h>

#define SIZE    100
// typedef double Op (double);

double plus1(double);
double minus1(double);
void transform(double source[], double target[], int, double (*) (double));

int main(int argc, char const *argv[])
{
    int i;
    double source[SIZE];
    for(i = 0; i < SIZE; i++) {
        source[i] = 1;
    }
    double target[SIZE];
    transform(source, target, SIZE, plus1);
    for(i = 0; i < SIZE; i++) {

        printf("%.2lf ", target[i]);
        if((i+1) % 10 == 0) {
            putchar('\n');
        }
    }
    transform(source, target, SIZE, minus1);
    for(i = 0; i < SIZE; i++) {

        printf("%.2lf ", target[i]);
        if((i+1) % 10 == 0) {
            putchar('\n');
        }
    }
    transform(source, target, SIZE, cos);
    for(i = 0; i < SIZE; i++) {

        printf("%.2lf ", target[i]);
        if((i+1) % 10 == 0) {
            putchar('\n');
        }
    }
    transform(source, target, SIZE, sin);
    for(i = 0; i < SIZE; i++) {

        printf("%.2lf ", target[i]);
        if((i+1) % 10 == 0) {
            putchar('\n');
        }
    }
    return 0;
}
void transform(double source[], double target[], int n, double (*op) (double)) {
    int i;
    for(i = 0; i < n; i++) {
        target[i] = op(source[i]);
    }
}

double plus1(double d) {
    return d+1;

}
double minus1(double d) {
    return d-1;
}