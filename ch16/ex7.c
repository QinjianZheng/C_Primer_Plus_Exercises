/* 7
下面是使用变参函数的一个程序段: 见以下程序
new_d_array()函数接受一个int类型的参数和double类型的参数。
该函数返回一个指针，指向由malloc()分配的内存块。
int类型的参数指定了动态数组中的元素个数，
double类型的值用于初始化元素(第1个值赋给第1个元素，以此类推)。
编写show_array()和new_d_array()函数的代码，完成这个程序。
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void show_array(const double ar[], int n);
double * new_d_array(int n, ...);

int main() {
    double * p1;
    double * p2;
    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0); 
    show_array(p1, 5);
    show_array(p2, 4);
    free(p1);
    free(p2);
    return 0;
}


void show_array(const double ar[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%8.3f ", ar[i]);
        if((i+1) % 6 == 0) {
            putchar('\n');
        }
    }
    putchar('\n');
}
double * new_d_array(int n, ...) {
    double *arr = malloc(n * sizeof(double));
    va_list ap;
    va_start(ap, n);
    for(int i = 0; i < n; i++) {
        arr[i] = va_arg(ap, double);
    }
    return arr;
}