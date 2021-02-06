/* 4

使用嵌套循环，按下面的格式打印字母:
A
BC
DEF
GHIJ
KLMNO
PQRSTU
如果你的系统不使用以数字顺序编码的代码，请参照练习3的方案解 决。

*/


#include <stdio.h>
#define SIZE 27

int main(int argc, char const *argv[])
{
    int x = 65;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j <= i; j++) {
            printf("%c", x++);
        }
        printf("\n");
    }
    return 0;
}