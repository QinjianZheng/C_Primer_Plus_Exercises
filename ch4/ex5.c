/* 5

编写一个程序，提示用户输入以兆位每秒(Mb/s)为单位的下载速度和以兆字节(MB)为单位的文件大小。
程序中应计算文件的下载时间。
注 意，这里1字节等于8位。
使用float类型，并用/作为除号。
该程序要以下面的格式打印3个变量的值(下载速度、文件大小和下载时间)，
显示小数点后面两位数字:
At 18.12 megabits per second, a file of 2.20 megabytes
downloads in 0.97 seconds.

*/


#include <stdio.h>
#define BIT_PER_BYTE    8


int main(int argc, char const *argv[])
{
    float speed;
    float size;
    printf("Enter the download speed(Mb/s): ");
    scanf("%f", &speed);
    printf("Enter the file size(MB): ");
    scanf("%f", &size);

    float time = size * BIT_PER_BYTE / speed;
    printf("At %.2f megabits per second, a file of %.2f megabytes downloads in %.2f seconds.\n",
            speed, size, time);
    return 0;
}
