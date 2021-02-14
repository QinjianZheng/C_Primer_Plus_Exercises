/* 2
编写一个程序，通过命令行参数读取两个二进制字符串，
对这两个二进制数使用~运算符、&运算符、|运算符和^运算符，
并以二进制字符串形式打印结果
(如果无法使用命令行环境，可以通过交互式让程序读取字符串)。

*/ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#define SIZE    9

int btoi(char *);
char * itobs(int, char *);

int main(int argc, char  *argv[])
{
    if(argc < 3) {
        printf("Usage %s binary binary\n", argv[0]);
        exit(1);
    }
    int binStr1 = btoi(argv[1]);
    int binStr2 = btoi(argv[2]);
    char bin_str1[SIZE];
    char bin_str2[SIZE];
    printf("~%s: %s\n~%s: %s\n", argv[1], itobs(~binStr1, bin_str1), 
                                argv[2], itobs(~binStr2, bin_str2));
    printf("(%s)&(%s) = %s\n", argv[1], argv[2], itobs((binStr1 & binStr2), bin_str1));
    printf("(%s)|(%s) = %s\n", argv[1], argv[2], itobs((binStr1 | binStr2), bin_str1));
    printf("(%s)^(%s) = %s\n", argv[1], argv[2], itobs((binStr1 ^ binStr2), bin_str1));
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
    i += (*p - '0') * pow(2, count);
    return i;
}
char * itobs(int n, char *binStr) {
    int i;
    const static int size = SIZE - 1;
    for(i = size - 1; i>=0; i--, n >>= 1) {
        binStr[i] = (01 & n) + '0';
    }
    binStr[size] = '\0';
    return binStr;
}