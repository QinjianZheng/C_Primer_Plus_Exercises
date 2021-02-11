/* 6

编写一个名为is_within()的函数，
接受一个字符和一个指向字符串的指针作为两个函数形参。
如果指定字符在字符串中，该函数返回一个非零值(即为真)。
否则，返回0(即为假)。
在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。

*/ 

#include <stdio.h>
#define MAX_LINE    100

int is_within(char *, char);

int main(int argc, char const *argv[])
{
    char string[MAX_LINE];
    fgets(string, MAX_LINE, stdin);
    
    char ch = ' ';
    while(ch != EOF) {
        printf("Enter a char: ");
        while((ch = getchar()) == '\n') {
            continue;
        }
        if(is_within(string, ch)) {
            printf("%c is in %s", ch, string);
        } else {
            printf("%c is not in %s", ch, string);
        }

    }

    return 0;
}

int is_within(char *string, char ch) {
    while(*string != '\0') {
        if(*string == ch) {
            return 1;
        } else {
            string ++;
        }
        
    }
    return 0;
}
