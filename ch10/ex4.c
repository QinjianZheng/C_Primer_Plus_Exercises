/* 4

编写一个函数，返回储存在double类型数组中最大值的下标，并在一个简单的程序中测试该函数
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE    8

int maxValueIndex(double [], int);
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

    printf("max value: %.1lf | index: %d\n", 
            array[maxValueIndex(array, SIZE)], maxValueIndex(array, SIZE));
    return 0;
}

int maxValueIndex(double array[], int n) {
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(array[i] > array[index]) {
            index = i;
        }
    }
    return index;
}