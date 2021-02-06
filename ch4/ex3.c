/* 3
.编写一个程序，读取一个浮点数，
首先以小数点记数法打印，然后以指数记数法打印。
用下面的格式进行输出(系统不同，指数记数法显示的位数可能不同):
a.输入21.3或2.1e+001;
b.输入+21.290或2.129E+001;
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    float f;
    printf("Enter a float point number: ");
    scanf("%f", &f);
    printf("%.1f | %.1e\n", f, f);
    if(f > 0) {
        printf("+");
    }
    
    printf("%.3f | %.3e\n", f, f);
    return 0;
}
