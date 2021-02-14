/* 5
编写一个函数，把一个 unsigned int 类型值中的所有位向左旋转指定数量的位。
例如，rotate_l(x, 4)把x中所有位向左移动4个位置，
而且从最左端移出的位会重新出现在右端。
也就是说，把高阶位移出的位放入低阶位。在一个程序中测试该函数。

*/ 

#include <stdio.h>
#include <limits.h>
#define SIZE    CHAR_BIT * sizeof(int) + 1

char * itobs(int n, char *binStr) {
    int i;
    const static int size = SIZE - 1;
    for(i = size - 1; i>=0; i--, n >>= 1) {
        binStr[i] = (01 & n) + '0';
    }
    binStr[size] = '\0';
    return binStr;
}

void rotate_l(u_int32_t, int);

int main(int argc, char const *argv[])
{
    u_int32_t n;
    int distance;
    printf("Please enter an integer: ");
    scanf("%d", &n);
    printf("Please enter the distance for rotating left: ");
    scanf("%d", &distance);
    rotate_l(n, distance);
    return 0;
}

void rotate_l(u_int32_t n, int distance) {
    char binStr[SIZE];
    char backup[distance + 1];
    printf("%s\n", itobs(n, binStr));
    char *p = binStr;
    char *b = backup;
    while(p != binStr + distance) {
        *(b++) = *(p++);
    }
    n <<= distance;
    printf("backup: %s\n", backup);
    printf("%s\n", itobs(n, binStr));
    b = backup + distance;
    p = binStr + SIZE - 1;
    while(b != backup) {
        *(p--) = *(b--);
    }
    printf("%s\n", binStr);

}