/* 3

编写一个函数，接受3个参数:
一个字符和两个整数。
字符参数是待 打印的字符，
第1个整数指定一行中打印字符的次数，
第2个整数指定打印指定字符的行数。
编写一个调用该函数的程序
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
    for(int x = 0; x < j; x++) {
        for(int y = 0; y < i; y++) {
            printf("%c ", ch);
        }
        putchar('\n');
    }
    
}