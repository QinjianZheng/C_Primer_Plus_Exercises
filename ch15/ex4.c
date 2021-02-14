/* 4

编写一个程序，接受两个int类型的参数:
一个是值;一个是位的位置。
如果指定位的位置为1，该函数返回1;否则返回0。
在一个程序中测试该函数。

*/ 

#include <stdio.h>
#include <limits.h>
int checkBitStatus(int n, int index);

char * itobs(int n, char *binStr) {
    int i;
    const static int size = CHAR_BIT * sizeof(int);
    for(i = size - 1; i>=0; i--, n >>= 1) {
        binStr[i] = (01 & n) + '0';
    }
    binStr[size] = '\0';
    return binStr;
}

int main(int argc, char const *argv[])
{
    int n;
    int index;
    printf("Please enter an integer for number: ");
    scanf("%d", &n);
    printf("Please enter an integer for index of bit: ");
    scanf("%d", &index);
    printf("%d bit of %d is %d\n", index, n, checkBitStatus(n, index));
    return 0;
}

int checkBitStatus(int n, int index) {
    int mask = 01;
    char binStr[CHAR_BIT * sizeof(int) + 1];
    printf("%3d: %s\n", n, itobs(n, binStr));
    n >>= index;
    printf("%3d: %s\n", n, itobs(n, binStr));
    return (n & mask);
}


