/* 4
使用if else语句编写一个程序读取输入，读到#停止。

用感叹号替换句号，用两个感叹号替换原来的感叹号，最后报告进行了多少次替换。

*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char ret;
    int count = 0;
    while((ret = getchar()) != '#') {
        if(ret == '.') {
            putchar('!');
            count ++;
        } else if(ret == '!') {
            printf("!!");
            count ++;
        } else {
            putchar(ret);
        }
    }
    putchar('\n');
    printf("count: %d\n", count);
    return 0;
}