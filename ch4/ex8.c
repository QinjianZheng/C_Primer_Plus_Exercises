/* 8
编写一个程序，提示用户输入旅行的里程和消耗的汽油量。
然后计算并显示消耗每加仑汽油行驶的英里数，显示小数点后面一位数字。
接下来，使用1加仑大约3.785升，1英里大约为1.609千米，
把单位是英里/加仑的值转 换为升/100公里(欧洲通用的燃料消耗表示法)，
并显示结果，显示小数点后面1位数字。
注意，美国采用的方案测量消耗单位燃料的行程(值越大越 好)，
而欧洲则采用单位距离消耗的燃料测量方案(值越低越好)。

使用 #define 创建符号常量或使用 const 限定符创建变量来表示两个转换系数。

*/

#include <stdio.h>
#define LITTER_PER_GALLON  3.785
#define KM_PER_MILE        1.609

int main(int argc, char const *argv[])
{
    float mile, gallon, km, litter;
    printf("mile: ");
    scanf("%f", &mile);
    printf("gallon: ");
    scanf("%f", &gallon);
    float milePerGallon = mile / gallon;
    printf("mile per gallon: %.3f\n", milePerGallon);

    km = KM_PER_MILE * mile;
    litter = LITTER_PER_GALLON * gallon;
    float litterPer100Km = litter / (100 * km);

    printf("litter per 100 km: %.3f\n", litterPer100Km);

    return 0;
}
