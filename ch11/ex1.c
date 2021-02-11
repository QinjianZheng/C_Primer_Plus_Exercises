/* 1

设计并测试一个函数，从输入中获取下n个字符(包括空白、制表符、换行符)，
把结果储存在一个数组里，它的地址被传递作为一个参数

*/ 

#include <stdio.h>
#define MAX_LINE    100

int setValue(char [], int n);

int main(int argc, char const *argv[])
{
    int count;
    char string[MAX_LINE];
    count = setValue(string, MAX_LINE);
    for(int i = 0; i < count; i++) {
        if(string[i] == ' ' || string[i] == '\t' || string[i] == '\n') {
            printf("#");
        } else {
            printf("%c", string[i]);
        }
    }
    putchar('\n');
    printf("count: %d\n", count);
    return 0;
}

int setValue(char string[], int n) {
    int count = 0;
    char ch;
    while(count < n && (ch = getchar()) != EOF) {
        string[count] = ch;
        count ++;
    }
    return count;
}