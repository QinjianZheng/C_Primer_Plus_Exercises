/* 7

编写一个程序，初始化一个double类型的二维数组，
使用编程练习2中 的一个拷贝函数把该数组中的数据拷贝至另一个二维数组中
(因为二维数组是数组的数组，所以可以使用处理一维数组的拷贝函数来处理数组中的每个子数组)。
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE    8

void copy_arr(double target[], double source[], int n) {
    for(int i = 0; i < n; i++) {
        target[i] = source[i];
    }
}
void print2DArray(int, int, double array[*][*]);



void print2DArray(int m, int n, double array[m][n]) {
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            printf("%3.0lf ", array[j][i]);
        }
        putchar('\n');
    }
    
}


int main(int argc, char const *argv[])
{
    double array[SIZE][SIZE];
    double target[SIZE][SIZE] = {0};
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++)
            array[i][j] = rand() % 100;
    }
    print2DArray(SIZE, SIZE, array);
    print2DArray(SIZE, SIZE, target);
    putchar('\n');
    for(int i = 0; i < SIZE; i++) {
        copy_arr(target[i], array[i], SIZE);
    }
        
    print2DArray(SIZE, SIZE, array);
    print2DArray(SIZE, SIZE, target);
    
    return 0;
}
