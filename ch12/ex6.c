/* 6
编写一个程序，生成1000个1~10范围内的随机数。
不用保存或打印 这些数字，仅打印每个数出现的次数。
用 10 个不同的种子值运行，生成的 数字出现的次数是否相同?
可以使用本章自定义的函数或ANSI C的rand()和 srand()函数，
它们的格式相同。这是一个测试特定随机数生成器随机性的方 法。

*/ 

#include <stdio.h>
#include <stdlib.h>
#define SIZE    1000
#define RANGE   11


int main(int argc, char const *argv[])
{
    
    for(int i = 0; i < RANGE - 1; i++) {
        int array[RANGE] = {0};
        srand(i);
        for(int i = 0; i < SIZE; i ++) {
            array[(rand() % 10) + 1] ++;
        }
        
        for(int i = 1; i < RANGE; i++) {
            printf("%3d ", i);
        }
        putchar('\n');
        for(int i = 1; i < RANGE; i++) {
            printf("%3d ", array[i]);
        }
        putchar('\n');
    }
    
    return 0;
}
