/* 6

编写并测试一个函数，该函数以3个double变量的地址作为参数，
把最小值放入第1个变量，中间值放入第2个变量，最大值放入第3个变量。

*/

#include <stdio.h>

void orderV1(double *, double *, double *);
void orderSol(double *, double *, double *);


int main(int argc, char const *argv[])
{
    double n1 = 9853.1324;
    double n2 = 1212.2334;
    double n3 = 5423.12423;
    printf("n1: %lf | n2: %lf | n3: %lf\n", n1, n2, n3);
    orderSol(&n1, &n2, &n3);
    printf("n1: %lf | n2: %lf | n3: %lf\n", n1, n2, n3);
    return 0;
    
}

static void swap(double *p1, double *p2) {
    double temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void orderV1(double *p1, double *p2, double *p3) {
    double max, min, middle;
    max = min = middle = *p1;
    if(*p2 > max) {
        max = *p2;
    }
    if(*p3 > max) {
        max = *p3;
    }
    if(*p2 < min) {
        min = *p2;
    }
    if(*p3 < min) {
        min = *p3;
    }
    if(*p1 != max && *p1 != min) {
        middle = *p1;
    } else if(*p2 != max && *p2 != min) {
        middle = *p2;
    } else if(*p3 != max && *p3 != min) {
        middle = *p3;
    }
    *p1 = min;
    *p2 = middle;
    *p3 = max;
}

void orderSol(double *p1, double *p2, double *p3) {
    if(*p1 > *p2) {
        swap(p1, p2);
    }
    if(*p1 > *p3) {
        swap(p1, p3);
    }
    if(*p2 > *p3) {
        swap(p2, p3);
    }


}