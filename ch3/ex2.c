/* 2
编写一个程序，要求提示输入一个ASCII码值(如，66)，然后打印 输入的字符。

*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    printf("Please enter an ASCII code: ");
    scanf("%d", &n);
    printf("%d: %c\n", n, n);
    return 0;
}
