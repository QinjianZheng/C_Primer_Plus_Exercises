/* 4

设计并测试一个函数，它类似编程练习3的描述，只不过它接受第2个参数指明可读取的最大字符数。

*/ 

#include <stdio.h>
#include <ctype.h>
#define MAX_LINE    100

void getWord(char *, int );

int main(int argc, char const *argv[])
{
    char string[MAX_LINE];
    // scanf("%s", string);
    getWord(string, MAX_LINE);
    printf("%s\n", string);
    return 0;
}

void getWord(char *string, int n) {
    char input[n];
    char *in = input;
    puts("Enter a string.");
    fgets(input, n, stdin);

    while(!isalpha(*in)) {
        in++;
    }
    while(isalpha(*in)) {
        *string = *in;
        string++;
        in++;
    }
}
