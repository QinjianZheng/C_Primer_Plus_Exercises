/* 9

编写一个程序，只接受正整数输入，然后显示所有小于或等于该数的素数。

*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num;
    int ret;
    char isPrime;
    printf("Please enter a positive integer: ");
    ret = scanf("%d", &num);
    if(ret == 1 && num > 0) {
        for(int i = 2; i <= num; i++) {
            isPrime = 1;
            for(int j = 2; j < num/2; j++) {
                if(i % j == 0 && i != j) {
                    isPrime = 0;
                }
            }
            if(isPrime) {
                printf("%d ", i);
            }
        }
    }
    putchar('\n');
    return 0;
}
