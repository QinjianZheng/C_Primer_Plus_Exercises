/* 8
修改练习7的假设a，让程序可以给出一个供选择的工资等级菜单。
使用switch完成工资等级选择。
运行程序后，显示的菜单应该类似这样:
***************************************************************** 
Enter the number corresponding to the desired pay rate or action:
1) $8.75/hr              2) $9.33/hr
3) $10.00/hr             4) $11.20/hr
5) quit
*****************************************************************

如果选择1~4其中的一个数字，程序应该询问用户工作的小时数。
程序要通过循环运行，除非用户输入5。
如果输入1~5以外的数字，程序应提醒用户输入正确的选项，然后再重复显示菜单提示用户输入。
使用#define创建符号常量表示各工资等级和税率。
*/

#include <stdio.h>
#define BASE 10
#define OVERTIME_HOUR_MUL 1.5
#define NORMAL_HOUR 40
#define FIRST_BUCKET  300
#define SECOND_BUCKET 450
#define RATE_LOWER_THAN_300    0.15
#define RATE_LOWER_THAN_450    0.20
#define RATE_HIGHER_THAN_450   0.25

int main(int argc, char const *argv[])
{
    int choice;
    int hour;
    float sararyRate;
    float sarary;
    float tax;
    char quit = 0;
    char repeat = 0;
    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action: \n");
    printf("1) $8.75/hr\t2) $9.33/hr\n3) $10.00/hr\t4) $11.20/hr\n5) quit\n");
    printf("*****************************************************************\n");
    while(scanf("%d", &choice)) {
        switch (choice)
        {
        case 1:
            sararyRate = 8.75;
            quit = 0;
            repeat = 0;
            break;
        case 2:
            sararyRate = 9.33;
            quit = 0;
            repeat = 0;
            break;
        case 3:
            sararyRate = 10.00;
            quit = 0;
            repeat = 0;
            break;
        case 4:
            sararyRate = 11.2;
            quit = 0;
            repeat = 0;
            break;
        case 5:
            quit = 1;
            break;
        default:
            printf("Incorrect input.\n");
            repeat = 1;
            break;
        }
        if(quit) {
            break;
        }
        if(repeat) {
            continue;
        }
        printf("Please work hour per week: ");
        scanf("%d", &hour);

        if(hour <= NORMAL_HOUR) {
            sarary = BASE * hour;
        } else {
            sarary = BASE * (NORMAL_HOUR + (hour - NORMAL_HOUR) * OVERTIME_HOUR_MUL);
        }
        if(sarary <= FIRST_BUCKET) {
            tax = sarary * RATE_LOWER_THAN_300;
        } else if(sarary <= SECOND_BUCKET) {
            tax = FIRST_BUCKET * RATE_LOWER_THAN_300 + (sarary - FIRST_BUCKET) * RATE_LOWER_THAN_450;
        } else {
            tax = FIRST_BUCKET * RATE_LOWER_THAN_300 + \
                    (SECOND_BUCKET - FIRST_BUCKET) * RATE_LOWER_THAN_450 + \
                    (sarary - SECOND_BUCKET) * RATE_HIGHER_THAN_450;
        }

        printf("Total sarary: %.1f\nTotal tax: %.1f\nNet sarary: %1.f\n", sarary, tax, sarary - tax);
        printf("*****************************************************************\n");
        printf("Enter the number corresponding to the desired pay rate or action: \n");
        printf("1) $8.75/hr\t2) $9.33/hr\n3) $10.00/hr\t4) $11.20/hr\n5) quit\n");
        printf("*****************************************************************\n");
    }
    printf("Done!\n");
    return 0;
}
