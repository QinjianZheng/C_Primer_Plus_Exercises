/* 2

设计一个函数chline(ch, i, j)，打印指定的字符j行i列。
在一个简单的驱动程序中测试该函数。
*/

#include <stdio.h>

void chline(char, int, int);

int main(int argc, char const *argv[])
{
    char ch = 'a';
    int i = 2;
    int j = 3;
    chline(ch, i, j);
    return 0;
}

void chline(char ch, int i, int j) {
    for(int x = 0; x < i; x++) {
        for(int y = 0; y < j; y++) {
            printf("%c ", ch);
        }
        putchar('\n');
    }
    
}
