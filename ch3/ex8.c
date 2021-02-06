/* 8
在美国的体积测量系统中，1品脱等于2杯，1杯等于8盎司，
1盎司等于2大汤勺，1大汤勺等于3茶勺。
编写一个程序，提示用户输入杯数，
并以品脱、盎司、汤勺、茶勺为单位显示等价容量。
思考对于该程序，为何使用 浮点类型比整数类型更合适?

*/

#include <stdio.h>
#define  CUP_PER_PINT             2.0
#define  OUNCE_PER_CUP            8.0
#define  SOUP_SPOON_PER_OUNCE     2.0
#define  TEA_SPOON_PER_SOUP_SPOON 3.0


int main(int argc, char const *argv[])
{
    int cup;
    float pint;
    float ounce;
    float soupSpoon;
    float teaSpoon;
    printf("How many cups do you have? ");
    scanf("%d", &cup);

    pint = cup / CUP_PER_PINT; // the number of cup could be odd
    ounce = cup * OUNCE_PER_CUP;
    soupSpoon = ounce * SOUP_SPOON_PER_OUNCE;
    teaSpoon = soupSpoon * TEA_SPOON_PER_SOUP_SPOON;

    printf("You have %.1f pints/ %.1f ounces/ %.1f soup spoons/ %.1f tea spoons.\n", 
                                            pint, ounce, soupSpoon, teaSpoon);
    return 0;
}
