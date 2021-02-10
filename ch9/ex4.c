/* 4

两数的调和平均数这样计算:
先得到两数的倒数，然后计算两个倒数的平均值，最后取计算结果的倒数。

编写一个函数，接受两个double类型的参数，返回这两个参数的调和平均数。

*/

#include <stdio.h>

double harmonicMean(double, double);

int main(int argc, char const *argv[])
{
    double n1 = 1212.2334;
    double n2 = 5423.12423;
    double res = harmonicMean(n1, n2);
    printf("n1: %lf | n2: %lf\n", n1, n2); 
    printf("mean: %lf\n", (n1+n2)/2);
    printf("harmonic mean: %lf\n", res);
    return 0;

}

double harmonicMean(double n1, double n2) {
    return (1.0/((1.0/n1 + 1.0/n2)/2));
}
