/* 14
数字图像，尤其是从宇宙飞船发回的数字图像，
可能会包含一些失真。
为编程练习12添加消除失真的函数。
该函数把每个值与它上下左右相邻的值作比较，如果该值与其周围相邻值的差都大于1，
则用所有相邻值的平均值(四舍五入为整数)代替该值。
注意，与边界上的点相邻的点少于4个，所以需要做特殊处理。

*/ 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "ex14.h"
#define UP(arr, i, j)  arr[i-1][j]
#define DOWN(arr, i, j) arr[i+1][j]
#define LEFT(arr, i, j) arr[i][j-1]
#define RIGHT(arr, i, j) arr[i][j+1]


void eliminateDistortion(int row, int col, int arr[row][col]) {
    int i, j;
    for(i = 1; i < row - 1; i++) {
        for(j = 1; j < col - 1; j++) {
            // 上
            if((abs(arr[i][j] - UP(arr, i, j)) > 1) && 
               (abs(arr[i][j] - DOWN(arr, i, j)) > 1) && 
               (abs(arr[i][j] - LEFT(arr, i, j)) > 1) && 
               (abs(arr[i][j] - RIGHT(arr, i, j)) > 1)) {
                   arr[i][j] = lround((UP(arr, i, j) + DOWN(arr, i, j) + 
                            LEFT(arr, i, j) + RIGHT(arr, i, j)) / 4.0);
            } 
        }
    }
}
