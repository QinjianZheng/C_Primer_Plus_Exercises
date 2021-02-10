/* 8

使用编程练习2中的拷贝函数，把一个内含7个元素的数组中第3~第5个元素拷贝至内含3个元素的数组中。
该函数本身不需要修改，只需要选择合适的实际参数
(实际参数不需要是数组名和数组大小，只需要是数组元素的地址和待处理元素的个数)。

*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE    7
#define TARGET_SIZE 3
void copy_arr(double target[], double source[], int n) {
    for(int i = 0; i < n; i++) {
        target[i] = source[i];
    }
}
void printArray(double array[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%.0lf ", array[i]);
    }
    putchar('\n');
}

int main(int argc, char const *argv[])
{
    double array[SIZE];
    double target[TARGET_SIZE]= {0};
    for(int j = 0; j < SIZE; j++)
        array[j] = rand() % 100;

    printArray(array, SIZE);
    putchar('\n');
    printArray(target, TARGET_SIZE);
    putchar('\n');
    
    copy_arr(target, array + 2, TARGET_SIZE);
        
    printArray(array, SIZE);
    putchar('\n');
    printArray(target, TARGET_SIZE);
    
    return 0;
}
