/* 3
使用嵌套循环，按下面的格式打印字母:
F
FE
FED
FEDC
FEDCB
FEDCBA
注意:如果你的系统不使用ASCII或其他以数字顺序编码的代码，可以 把字符数组初始化为字母表中的字母:
char lets[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

然后用数组下标选择单独的字母，例如lets[0]是‘A’，等等。

*/

#include <stdio.h>
#define SIZE 27

int main(int argc, char const *argv[])
{
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j <= i; j++) {
            printf("%c", 70-j);
        }
        printf("\n");
    }
    return 0;
}