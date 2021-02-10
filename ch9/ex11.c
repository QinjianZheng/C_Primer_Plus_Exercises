/* 11

编写并测试Fibonacci()函数，该函数用循环代替递归计算斐波那契数。
*/

#include <stdio.h>

unsigned long Fibonacci(unsigned n) {
    unsigned long res = 1;
    int i;
    unsigned long prev2, prev1;
    prev2 = prev1 = 1;
    for(i = 3; i <= n; i++) {
        prev2 = prev1;
        prev1 = res;
        res = prev1 + prev2;
    }
    return res;
}


int main(int argc, char const *argv[])
{
    unsigned n;
    printf("Please enter the limit: ");
    scanf("%u", &n);
    for(int i = 1; i <= n; i++) {
        printf("%lu ", Fibonacci(i));
    }
    putchar('\n');
    return 0;
}
