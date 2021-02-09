/* 11

编写一个程序，在数组中读入8个整数，然后按倒序打印这8个整数。

*/

#include <stdio.h>
#define SIZE 8

int main(int argc, char const *argv[])
{
    int array[SIZE];
    for(int i = 0; i < SIZE; i++) {
        scanf("%d", &array[i]);
    }
    for(int i = SIZE -1 ; i >= 0; i--) {
        printf("%d ", array[i]);
    }
    putchar('\n');
    return 0;
}
