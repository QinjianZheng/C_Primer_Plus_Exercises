/* 1

设计一个程序，统计在读到文件结尾之前读取的字符数。
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char ch;
    int count = 0;
    while(scanf("%c", &ch) != EOF) {
        printf("%c", ch);
        count++;
    }
    printf("\ncount = %d\n", count);
    return 0;
}
