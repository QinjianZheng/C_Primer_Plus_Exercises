/* 5

使用switch重写练习4。

*/

#include <stdio.h>


int main(int argc, char const *argv[])
{
    char ret;
    int count = 0;
    while((ret = getchar()) != '#') {
        switch (ret)
        {
        case '.':
            putchar('!');
            count ++;
            break;
        case '!':
            printf("!!");
            count ++;
            break;
        default:
            putchar(ret);
            break;
        }
    }
    putchar('\n');
    printf("count: %d\n", count);
    return 0;
}