/* 7
strncpy(s1, s2, n)函数把s2中的n个字符拷贝至s1中，截断s2，
或者有必要的话在末尾添加空字符。
如果s2的长度是n或多于n，目标字符串不能以空字符结尾。
该函数返回s1。
自己编写一个这样的函数，名为mystrncpy()。
在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。

*/ 

#include <stdio.h>
#define MAX_LINE    100

char * mystrncpy(char *dest, char *src, int size);

int main(int argc, char const *argv[])
{
    char string[MAX_LINE];
    printf("Enter a string: ");
    while((fgets(string, MAX_LINE, stdin)) != NULL) {
        printf("source string: %s", string);
        char target[MAX_LINE];
        mystrncpy(target, string, 5);
        printf("target string: %s\n", target);
        printf("Enter a string: ");
    }
    

    return 0;
}

char * mystrncpy(char *dest, char *src, int size) {
    char *p = src;
    int count = 0;
    while(count < size && *p != '\0') {
        *dest++ = *p++;
        count ++;
    }
    *dest = '\0';

    return dest;
}