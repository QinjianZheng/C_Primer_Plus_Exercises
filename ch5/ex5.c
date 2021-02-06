/* 5

修改程序addemup.c(程序清单5.13)，
你可以认为addemup.c是计算20天里赚多少钱的程序
(假设第1天赚$1、第2天赚$2、第3天赚$3，以此类 推)。

修改程序，使其可以与用户交互，
根据用户输入的数进行计算(即， 用读入的一个变量来代替20)。

*/

#include <stdio.h>

int main(int argc, char const *argv[]){
    int count, sum;
    int num;
    count = 0;
    sum = 0;
    printf("Please enter a num: ");
    scanf("%d", &num);
    while (count++ < num) {
        sum = sum + count;
        printf("count=%d, sum=%d\n", count, sum);
    }
    printf("sum=%d\n", sum);
    return 0;
}