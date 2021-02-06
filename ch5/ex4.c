/* 4

编写一个程序，提示用户输入一个身高(单位:厘米)，
并分别以厘 米和英寸为单位显示该值，允许有小数部分。
程序应该能让用户重复输入身 高，直到用户输入一个非正值。
其输出示例如下:
Enter a height in centimeters: 182 
182.0 cm = 5 feet, 11.7 inches 
Enter a height in centimeters (<=0 to quit): 168.7 
168.0 cm = 5 feet, 6.4 inches 
Enter a height in centimeters (<=0 to quit): 0
bye

*/
#include <stdio.h>
#define INCH_PER_CM 0.39370
#define INCH_PER_FOOT 12

int main(int argc, char const *argv[])
{
    float height_cm;
    float height_inch;
    int height_foot;
    float left;
    printf("Please enter the height in centimeters: ");
    scanf("%f", &height_cm);
    while (height_cm > 0) {
        height_inch = INCH_PER_CM * height_cm;
        height_foot = height_inch / INCH_PER_FOOT;
        left = height_inch - INCH_PER_FOOT * height_foot;
        printf("%.1f cm = %d feet, %.1f inches.\n",
               height_cm, height_foot, left);
        printf("Please enter the height in centimeters (<=0 to quit): ");
        scanf("%f", &height_cm);
    }
    printf("bye");
    return 0;
}
