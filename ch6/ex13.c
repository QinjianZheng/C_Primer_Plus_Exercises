/* 13
编写一个程序，创建一个包含8个元素的int类型数组，
分别把数组元素设置为2的前8次幂。
使用for循环设置数组元素的值，使用do while循环显示数组元素的值。

*/

#include <stdio.h>
#include <math.h>
#define SIZE    8

int main(int argc, char const *argv[])
{
    int array[SIZE];
    int i;
    for(i = 0; i < SIZE; i++) {
        array[i] = pow(2, i+1);
    }
    i = 0;
    do {
        printf("%d ", array[i]);
        i++;
    } while(i < SIZE);
    putchar('\n');
    return 0;
}
