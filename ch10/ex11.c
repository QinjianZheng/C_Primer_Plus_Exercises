/* 11

编写一个程序，声明一个int类型的3×5二维数组，
并用合适的值初始 化它。
该程序打印数组中的值，然后各值翻倍(即是原值的2倍)，
并显示 出各元素的新值。
编写一个函数显示数组的内容，再编写一个函数把各元素的值翻倍。
这两个函数都以函数名和行数作为参数。
*/

#include <stdio.h>
#include <stdlib.h>
#define ROWS    3
#define COLS    5

void doubleArray(int, int, double array[*][*]);


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
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++)
            array[i][j] = rand() % 100;
    }
    print2DArray(ROWS, COLS, array);
    putchar('\n');
    doubleArray(ROWS, COLS, array);
        
    print2DArray(ROWS, COLS, array);
    
    
    return 0;
}

void doubleArray(int row, int col, double array[row][col]) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            array[i][j] *= 2;
        }
    }
}