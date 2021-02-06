/* 6
1个水分子的质量约为3.0×10−23克。
1夸脱水大约是950克。
编写一个程序，提示用户输入水的夸脱数，并显示水分子的数量。

*/

#include <stdio.h>

#define MASS_PER_WATER_MOLECULE 3.0E-23
#define MASS_PER_QUART          950

int main(int argc, char const *argv[])
{
    int quart;
    printf("How many quarts of water do you have? ");
    scanf("%d", &quart);
    printf("You have %e water molecules.\n", quart * MASS_PER_QUART / MASS_PER_WATER_MOLECULE);

    return 0;
}
