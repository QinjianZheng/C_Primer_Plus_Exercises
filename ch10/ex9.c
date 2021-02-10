/* 9
编写一个程序，初始化一个double类型的3×5二维数组，
使用一个处理变长数组的函数将其拷贝至另一个二维数组中。
还要编写一个以变长数组为形参的函数以显示两个数组的内容。
这两个函数应该能处理任意N×M数组 (如果编译器不支持变长数组，就使用传统C函数处理N×5的数组)。
*/

#include <stdio.h>
#include <stdlib.h>
#define ROWS    3
#define COLS    5

void copy_arr(int row, int col, double target[row][col], double source[row][col]) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            target[i][j] = source[i][j];
        }
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
    double array[ROWS][COLS];
    double target[ROWS][COLS] = {0};
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++)
            array[i][j] = rand() % 100;
    }
    print2DArray(ROWS, COLS, array);
    print2DArray(ROWS, COLS, target);
    putchar('\n');
    copy_arr(ROWS, COLS, target, array);
        
    print2DArray(ROWS, COLS, array);
    print2DArray(ROWS, COLS, target);
    
    return 0;
}
