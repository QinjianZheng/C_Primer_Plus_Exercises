/* 7
编写一个程序，按照程序清单12.13输出示例后面讨论的内容，修改该程序。
使其输出类似:
Enter the number of sets; enter q to stop : 18
How many sides and how many dice? 6 3 
Here are 18 sets of 3 6-sided throws. 
12 10 6 9 8 14 8 15 9 14 12 17 11 7 10 13 8 14
How many sets? Enter q to stop: q
*/ 

/* manydice.c -- 多次掷骰子的模拟程序 */
/* 与 diceroll.c 一起编译*/
#include <stdio.h>
#include <stdlib.h>    /* 为库函数 srand() 提供原型 */
#include <time.h>     /* 为 time() 提供原型      */
#include "diceroll.h"   /* 为roll_n_dice()提供原型，为roll_count变量 提供声明 */
int main(void)
{
    int dice;
    int sides;
    int status;
    int sets;
    srand((unsigned int) time(0)); /* 随机种子 */ 
    printf("Enter the number of sets, q to stop.\n"); 
    while (scanf("%d", &sets) == 1) {
        printf("How many sides and how many dice?\n"); 
        while ((status = scanf("%d %d", &sides, &dice)) != 2) {
            if (status == EOF)
                break;       /* 退出循环 */
            else {
                printf("You should have entered an integer."); 
                printf(" Let's begin again.\n");
                while (getchar() != '\n')
                    continue;   /* 处理错误的输入 */ 
                
            }
            if(sides * dice != sets) {
                printf("The numbers of sides and dices don't add up to the sets.\n");
                printf("How many sides and how many dice?\n");
                continue;
            }
        }
        printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
        for(int i = 0;  i < sets; i++) {
            printf("%d ", roll_n_dice(dice, sides));
        }
        printf("\nHow many sets? Enter q to stop.\n");
    }
    printf("The rollem() function was called %d times.\n", roll_count);     /* 使用外部变量 */
    printf("GOOD FORTUNE TO YOU!\n"); 
    return 0; 
}
