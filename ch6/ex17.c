/* 17

Chuckie Lucky赢得了100万美元(税后)，
他把奖金存入年利率8%的账户。
在每年的最后一天， Chuckie取出10万美元。
编写一个程序，计算多少年后Chuckie会取完账户的钱?

*/

#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    float prize = 100;
    float rate = 0.08;
    int year = 0;
    do
    {
        year++;
        prize = prize * (1+rate) - 10;
        printf("year %2d | prize %6.2f\n", year, prize);
    } while (prize > 0);
    
    // printf("year: %d\n", year);

    return 0;
}
