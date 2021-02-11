/* 15
使用字符分类函数实现atoi()函数。
如果输入的字符串不是纯数字，该函数返回0。

*/ 

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE    12
int atoi(char *);

int main(int argc, char const *argv[])
{
    char string[MAX_LINE];
    int res = 0;
    printf("Enter a string: ");
    scanf("%s", string);
    if((res = atoi(string)) != 0 || *string == '0') {
        printf("%d\n", res);
    } else {
        printf("%s is not an integer\n", string);
    }
    return 0;
}

int atoi(char *string) {
    int res = 0;
    while(*string != '\0') {
        if(isnumber(*string)) {
            res = res * 10 + (*string - '0');
        } else {
            res = 0;
            break;
        }
        string++;

    }
    return res;
}