/* 5
编写一个函数接受这些参数:
内含int类型元素的数组名、
数组的大小 和一个代表选取次数的值。
该函数从数组中随机选择指定数量的元素，并打印它们。
每个元素只能选择一次(模拟抽奖数字或挑选陪审团成员)。
另外，如果你的实现有time()(第12章讨论过)或类似的函数，
可在srand()中使用这个函数的输出来初始化随机数生成器rand()。
编写一个简单的程序测 试该函数。

*/ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE    10
void pick(int [], int, int);

int main(int argc, char const *argv[])
{
    int i;
    srand((unsigned int)time(0));

    int arr[SIZE];
    for(i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }   
    printf("Array: ");
    for(i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    int times;
    printf("How many times you want to pick a number: ");
    scanf("%d", &times);
    pick(arr, SIZE, times);
    puts("Done.\n");
    return 0;
}

void pick(int arr[], int n, int times) {
    int i;
    int picked[n];
    int pick;
    int count = 0;
    for(i = 0; i < n; i++) {
        picked[i] = 0; 
    }

    while(count < times) {
        
        pick = rand() % n;
        printf("Picking %d\n", arr[pick]);
        if(picked[pick] == 0) {
            printf("You picked %d\n", arr[pick]);
            picked[pick] = 1;
            count ++;
        } else {
            printf("%d has already been picked.\n", arr[pick]);
        }
    }
}