/* 1
不使用全局变量，重写程序清单12.4。

*/ 

/* global.c -- 使用外部变量 */
#include <stdio.h>

void critic(int*);

int main(void) {
    int units; /* 可选的重复声明 */ 
    printf("How many pounds to a firkin of butter?\n"); 
    scanf("%d", &units);
    while (units != 56)
        critic(&units);
    printf("You must have looked it up!\n");
    return 0;
}

void critic(int *p) {
/* 删除了可选的重复声明 */ 
    printf("No luck, my friend. Try again.\n"); 
    scanf("%d", p);
}