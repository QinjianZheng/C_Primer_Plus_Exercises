/* 4

在一个循环中编写并测试一个函数，该函数返回它被调用的次数。
*/ 

#include <stdio.h>

int count;
int test(void);

int main(int argc, char const *argv[])
{
    int n;
    int count = 0;
    printf("how many times you want to call the function: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        count = test();
    }
    printf("count: %d\n", count);
    return 0;
}

int test(void) {
    count++;
    return count;
}
