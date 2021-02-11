/* 8

编写一个名为string_in()的函数，接受两个指向字符串的指针作为参数。
如果第2个字符串中包含第1个字符串，该函数将返回第1个字符串开始的地址。
例如，string_in("hats", "at")将返回hats中a的地址。
否则，该函数返回空指针。
在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
*/ 

#include <stdio.h>
#include <string.h>
#define MAX_LINE    100
char * string_in(char *, char *);

int main(int argc, char const *argv[])
{
    char string[MAX_LINE];
    char key[MAX_LINE];
    char *sub = NULL;
    printf("Please enter a string: ");
    fgets(string, MAX_LINE, stdin);
    printf("Please enter a keyword: ");
    fgets(key, MAX_LINE, stdin);
    while(*string != '\n') {
        if((sub = string_in(string, key)) != NULL) {
            printf("%s", sub);
        } else {
            printf("%s not found\n", key);
        }
        printf("Please enter a string: ");
        fgets(string, MAX_LINE, stdin);
        printf("Please enter a keyword: ");
        fgets(key, MAX_LINE, stdin);
    }
    
    
    return 0;
}

char *string_in(char *string, char *key) {
    char *p1, *p2;
    int count = 0;
    int len = strlen(key) -1; // 算长度去掉换行符
    p1 = string;
    p2 = key;
    while(*p1 != '\0' && count < len) {
        if(*(p1 + count) == *(p2 + count)) {
            count ++;
        } else {
            p1++;
            count = 0;
        }

    }
    if(count == len) {
        return p1;
    } else {
        return NULL;
    }
    
}