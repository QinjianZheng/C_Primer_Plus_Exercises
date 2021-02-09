/* 14

编写一个程序，创建两个包含8个元素的double类型数组，
使用循环提示用户为第一个数组输入8 个值。
第二个数组元素的值设置为第一个数组对应元素的累积之和。

例如，第二个数组的第4个元素的值是第一个数组前4个元素之和，
第二个数组的第5个元素的值是第一个数组前5个元素之和
(用嵌套循环可以完成，但是利用第二个数组的第5个元素是第二个数组的第4个元素与第一个数组的第5个元素之和，
只用一个循环就能完成任务，不需要使用嵌套循环)。
最后，使用循环显示两个数组的内容，第一个数组显示成一行，
第二个数组显示在第一个数组的下一行，而且每个元素都与第一个数组各元素相对应。

*/
#include <stdio.h>
#define SIZE    8

void calculateV1(double [], double [], int);

int main(int argc, char const *argv[])
{
    double array1[SIZE], array2[SIZE];
    printf("Please enter 8 numbers for the first array: \n");
    for(int i = 0; i < SIZE; i++) {
        scanf("%lf", &array1[i]);
    }
    calculateV1(array1, array2, SIZE);
    for(int i = 0; i < SIZE; i++) {
        printf("%6.2f ", array1[i]);
    }
    putchar('\n');
    for(int i = 0; i < SIZE; i++) {
        printf("%6.2f ", array2[i]);
    }
    putchar('\n');
    return 0;
}

void calculateV1(double array1[], double array2[], int n) {
    array2[0] = array1[0];
    for(int i = 1; i < n; i++) {
        array2[i] = array2[i-1] + array1[i];
    }
}