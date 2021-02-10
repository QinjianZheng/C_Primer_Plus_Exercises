/* 10
编写一个函数，把两个数组中相对应的元素相加，
然后把结果储存 到第 3 个数组中。
也就是说，如果数组1中包含的值是2、4、5、8，
数组2中 包含的值是1、0、4、6，
那么该函数把3、4、9、14赋给第3个数组。
函数接受3个数组名和一个数组大小。
在一个简单的程序中测试该函数。
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE    8

void sumArrs(int src1[], int src2[], int sum[], int n);

void printArray(int array[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%3d ", array[i]);
    }
    putchar('\n');
}

int main(int argc, char const *argv[])
{
    int array1[SIZE], array2[SIZE], array3[SIZE];
    for(int i = 0; i < SIZE; i++) {
        array1[i] = rand() % 100;
        array2[i] = rand() % 100;
        array3[i] = 0;
    }
    printArray(array1, SIZE);
    printArray(array2, SIZE);
    printArray(array3, SIZE);
    putchar('\n');
    sumArrs(array1, array2, array3, SIZE);
    printArray(array1, SIZE);
    printArray(array2, SIZE);
    printArray(array3, SIZE);
    return 0;
}

void sumArrs(int src1[], int src2[], int sum[], int n) {
    for(int i = 0; i < n; i++) {
        sum[i] = src1[i] + src2[i];
    }
}
