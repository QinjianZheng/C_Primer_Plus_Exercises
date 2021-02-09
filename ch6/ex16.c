/* 16
Daphne以10%的单利息投资了100美元(也就是说，每年投资获利相当于原始投资的10%)。
Deirdre以5%的复合利息投资了100美元(也就是说，利息是当前余额的5%，包含之前的利息)。

编写一个程序，计算需要多少年Deirdre的投资额才会超过Daphne，并显示那时两人的投资额。
*/

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int base = 100;
    float investDa = 100;
    float investDe = 100;
    int year = 0;
    do {
        year++;
        investDa += (0.1 * base);
        investDe = base * pow(1.05, year);
        
    } while(investDe < investDa);
    printf("year: %d\n", year);
    printf("Daphne investment: %f\n", investDa);
    printf("Deirdre investment: %f\n", investDe);
    return 0;
}
