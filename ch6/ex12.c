/* 12

考虑下面两个无限序列:
1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... 
1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...

编写一个程序计算这两个无限序列的总和，直到到达某次数。
提示:奇 数个-1 相乘得-1，偶数个-1相乘得1。
让用户交互地输入指定的次数，当用 户输入0或负值时结束输入。
查看运行100项、1000项、10000项后的总和，是否发现每个序列都收敛于某值?
*/

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int limit;
    printf("Please enter the limit: ");
    scanf("%d", &limit);


    
    double denominator = 1.0;
    double sum = 0.0;
    double sum1 = 0.0;
    double sum2 = 0.0;
    for(int i = 0; i < limit; i++, denominator++) {
        double sign = pow(-1, i);
        sum1 += 1.0/denominator;
        sum2 += sign * 1.0/denominator;
    }
    sum = sum1 + sum2;
    printf("sum1 = %f | sum2 = %f | sum = %f\n", sum1, sum2, sum);
    return 0;
}
