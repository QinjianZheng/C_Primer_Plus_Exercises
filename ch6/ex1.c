/* 1
编写一个程序，创建一个包含26个元素的数组，并在其中储存26个小
写字母。然后打印数组的所有内容。

*/

#include <stdio.h>
#define SIZE 27

int main(int argc, char const *argv[])
{
    char array[SIZE];
    for(int i = 0; i < SIZE; i++) {
        array[i] = i + 97;
    }
    for(int i = 0; i < SIZE; i++) {
        printf("%c ", array[i]);
    }
    putchar('\n');
    return 0;
}
