/* 1

编写一个程序读取输入，读到#字符停止，然后报告读取的空格数、
换行符数和所有其他字符的数量。

*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char ret;
    int spaceCount = 0;
    int tabCount = 0;
    int others = 0;
    while((ret = getchar()) != '#') {
        if(ret == ' ') {
            spaceCount ++;
        } else if(ret == '\n') {
            tabCount ++;
        } else {
            others ++;
        }
    }
    printf("space#: %d\ntab#: %d\nothers#: %d\n", spaceCount, tabCount, others);
    return 0;
}

