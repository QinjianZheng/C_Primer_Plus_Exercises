/* 2

修改并编程练习1的函数，在n个字符后停止，或在读到第1个空白、
制表符或换行符时停止，哪个先遇到哪个停止。不能只使用scanf()。

*/ 

#include <stdio.h>
#define MAX_LINE   5

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
    while(count < n && ((ch = getchar()) != ' ' && ch != '\t' && ch != '\n')) {
        string[count] = ch;
        count ++;
    }
    return count;
}