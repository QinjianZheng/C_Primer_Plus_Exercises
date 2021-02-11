/* 5

设计并测试一个函数，搜索第1个函数形参指定的字符串，
在其中查找第2个函数形参指定的字符首次出现的位置。
如果成功，该函数返指向该字符的指针，
如果在字符串中未找到指定字符，则返回空指针
(该函数的功能与 strchr()函数相同)。
在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。

*/ 

#include <stdio.h>
#define MAX_LINE    100

char * locateChr(char *, char);

int main(int argc, char const *argv[])
{
    char string[MAX_LINE];
    char ch;
    char *loc = NULL;
    printf("Enter a string:");
    while((fgets(string, MAX_LINE, stdin)) != NULL) {
        printf("Enter a character.");
        ch = getchar();
        if((loc = locateChr(string, ch)) != NULL) {
            printf("%s", loc);
        }
        printf("Enter a string:");
        while(getchar() == '\n')
            continue;
    }
    return 0;
}

char * locateChr(char *string, char ch) {
    char *p = string;
    while(*p != '\0') {
        if(*p == ch) {
            return p;
        }
        p++;
    }
    return NULL;
}