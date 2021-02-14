/* 3

编写一个函数，接受一个 int 类型的参数，并返回该参数中打开位的数量。
在一个程序中测试该函数。

*/ 

#include <stdio.h>
#include <limits.h>


char * itobs(int, char *);
int countOpenBits(int);

int main(int argc, char const *argv[])
{
    int n;
    
    printf("Please enter an integer: ");
    scanf("%d", &n);
    printf("Open bits : %d\n", countOpenBits(n));
    return 0;
}


char * itobs(int n, char *binStr) {
    int i;
    const static int size = CHAR_BIT * sizeof(int);
    for(i = size - 1; i>=0; i--, n >>= 1) {
        binStr[i] = (01 & n) + '0';
    }
    binStr[size] = '\0';
    return binStr;
}

int countOpenBits(int n) {
    int count = 0;
    char binStr[CHAR_BIT * sizeof(int) + 1];
    char *p = binStr;
    itobs(n, binStr);
    printf("%s\n", binStr);
    while(*p != '\0') {
        if(*p == '1') {
            count ++;
        }
        p ++;
    }
    return count;
}