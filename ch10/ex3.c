/* 3

编写一个函数，返回储存在int类型数组中的最大值，并在一个简单的程序中测试该函数。

*/

#include <stdio.h>
#define SIZE        8

int max(int [], int);
void printArray(int array[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    putchar('\n');
}

int main(int argc, char const *argv[])
{
    int array[SIZE];
    for(int i = 0; i < SIZE; i++) {
        array[i] = 2 * i + 3;
    }
    printArray(array, SIZE);
    printf("max value: %d\n", max(array, SIZE));
    return 0;
}

int max(int array[], int n) {
    int max = array[0];
    for(int i = 0; i < n; i++) {
        if(array[i] > max) {
            max = array[i];
        }
    }
    return max;
}