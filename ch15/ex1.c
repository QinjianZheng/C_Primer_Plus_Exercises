/* 1

编写一个函数，把二进制字符串转换为一个数值。
例如，有下面的语句:
char * pbin = "01001001";
那么把pbin作为参数传递给该函数后，它应该返回一个int类型的值25。
*/ 


#include <stdio.h>
#include <math.h>
#include <string.h>
#define SIZE    33

int btoi(char *);

int main(int argc, char const *argv[])
{
    char input[SIZE] = "01001001";
    printf("binary: %s to decimal: %d\n", input, btoi(input));

    return 0;
}

int btoi(char * b) {
    int i = 0;
    int count = 0;
    char *p = b + strlen(b) - 1;
    while(p != b) {
        i += (*p - '0') * pow(2, count);
        p--;
        count ++;
    }
    return i;
}

