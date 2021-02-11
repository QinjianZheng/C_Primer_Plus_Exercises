/* 11
编写一个程序，接受两个命令行参数。
第1个参数是一个字符串，第 2个参数是一个文件名。
然后该程序查找该文件，打印文件中包含该字符串的所有行。
因为该任务是面向行而不是面向字符的，所以要使用fgets()而不是getc()。
使用标准C库函数strstr()(11.5.7节简要介绍过)
在每一行中查找指定字符串。
假设文件中的所有行都不超过255个字符。

*/ 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define MAX     255

int main(int argc, char const *argv[])
{
    FILE *fp = fopen(argv[2], "r");
    assert(fp != NULL);
    char line[MAX];
    while(fgets(line, MAX, fp) != NULL) {
        if(strstr(line, argv[1]) != NULL) {
            fputs(line, stdout);
        }
    }
    return 0;
}

