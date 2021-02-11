/* 5
编写一个程序，生成100个1~10范围内的随机数，并以降序排列
(可以把第11章的排序算法稍加改动，便可用于整数排序，这里仅对整数排序)。

*/ 

#include <stdio.h>
#include <stdlib.h>
#define SIZE    100

void orderDec(int [], int);


int main(int argc, char const *argv[])
{
    int array[SIZE] = {0};
    int i;
    for(i = 0; i < SIZE; i++) {
        array[i] = (rand() % 10) + 1;
    }
    for(i = 0; i < SIZE; i++) {
        printf("%2d ", array[i]);
        if((i+1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    orderDec(array, SIZE);
    for(i = 0; i < SIZE; i++) {
        printf("%2d ", array[i]);
        if((i+1) % 10 == 0) {
            printf("\n");
        }
    }
    putchar('\n');
    return 0;
}

void orderDec(int array[], int n) {
    int i, j;
    int element;
    for(i = 1; i < n; i++) {
        j = i - 1;
        element = array[i];
        while(j >= 0 && array[j] < element) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = element;   //insert in correct position
    }
}