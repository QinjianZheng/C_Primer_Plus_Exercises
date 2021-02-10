/* 5

编写一个函数，返回储存在double类型数组中最大值和最小值的差值，
并在一个简单的程序中测试该函数。
*/


#include <stdio.h>
#include <stdlib.h>
#define SIZE    8

double range(double [], int);
void printArray(double array[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%.1lf ", array[i]);
    }
    putchar('\n');
}
int main(int argc, char const *argv[])
{
    double array[SIZE];
    for(int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
    }
    printArray(array, SIZE);

    printf("range: %.1lf\n", range(array, SIZE));
    return 0;
}

double range(double array[], int n) {
    double max = array[0];
    double min = array[0];

    for(int i = 0; i < n; i++) {
        if(array[i] > max) {
            max = array[i];
        }
        if(array[i] < min) {
            min = array[i];
        }
        
    }
    double r = max - min;

    return r;
}