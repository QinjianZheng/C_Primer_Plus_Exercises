/* 3
重新设计编程练习2，要求只使用自动变量。默认就是自动变量
该程序提供的用户界面不变，即提示用户输入模式等。
但是，函数调用要作相应变化。
*/ 

#include <stdio.h>
#include "pe12-3a.h"

int main(void) {
    int mode; 
    int fallbackMode = 0;
    float distance;
    float fuel;
    printf("Enter 0 for metric mode, 1 for US mode: "); 
    scanf("%d", &mode);
    while (mode >= 0) {
        get_info(&mode, &fallbackMode, &distance, &fuel);
        show_info(mode, distance, fuel);

        printf("Enter 0 for metric mode, 1 for US mode"); 
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}