/* 9

编写一个函数，把字符串中的内容用其反序字符串代替。
在一个完整 的程序中测试该函数，使用一个循环给函数提供输入值。
*/ 

#include <stdio.h>
#include <string.h>
#define MAX_LINE    100

char *reverse(char *);

int main(int argc, char const *argv[])
{
    char string[MAX_LINE];
    do
    {
        printf("Enter a string: ");
        fgets(string, MAX_LINE, stdin);
        reverse(string);
        printf("%s", string);
    } while (*string != '\n');
    
    return 0;
}

char *reverse(char *string) {
    char *p1, *p2;
    char temp;
    p1 = string;
    p2 = string + strlen(string) - 2;
    while(p1 != p2 && p1 - p2 != 1) {
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        p1++;
        p2--;
    }
    return string;
}

