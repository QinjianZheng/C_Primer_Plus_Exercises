/* 3
设计并测试一个函数，从一行输入中把一个单词读入一个数组中，并丢弃输入行中的其余字符。
该函数应该跳过第1个非空白字符前面的所有空白。
将一个单词定义为没有空白、制表符或换行符的字符序列

*/ 

#include <stdio.h>
#include <ctype.h>
#define MAX_LINE    100

void getWord(char *);

int main(int argc, char const *argv[])
{
    char string[MAX_LINE];
    // scanf("%s", string);
    getWord(string);
    printf("%s\n", string);
    return 0;
}

void getWord(char *string) {
    char input[MAX_LINE];
    char *in = input;
    puts("Enter a string.");
    fgets(input, MAX_LINE, stdin);

    while(!isalpha(*in)) {
        in++;
    }
    while(isalpha(*in)) {
        *string = *in;
        string++;
        in++;
    }
}

