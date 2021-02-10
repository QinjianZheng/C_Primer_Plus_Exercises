/* 6

编写一个函数，把double类型数组中的数据倒序排列，并在一个简单的程序中测试该函数。

*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE    8

void reverse(double [], int);
void printArray(double array[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%.0lf ", array[i]);
    }
    putchar('\n');
}
int main(int argc, char const *argv[])
{
    double array[SIZE];
    for(int i = 0; i < SIZE; i++) {
        array[i] = i;
    }
    printArray(array, SIZE);

    reverse(array, SIZE);
    printArray(array, SIZE);
    return 0;
}

void reverse(double array[], int n) {
    int i, j;
    double temp;
    for(i = 0, j = n-1; i != j && i - j != 1; i++, j--) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}