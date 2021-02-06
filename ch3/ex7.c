/* 7
1英寸相当于2.54厘米。
编写一个程序，提示用户输入身高(/英寸)，然后以厘米为单位显示身高.

*/

#include <stdio.h>
#define CM_PER_INCH  2.54

int main(int argc, char const *argv[])
{
    int ht_inch;
    printf("How tall are you? ");
    scanf("%d", &ht_inch);

    printf("You are %.2f cm tall.\n", ht_inch * CM_PER_INCH);
    return 0;
}
