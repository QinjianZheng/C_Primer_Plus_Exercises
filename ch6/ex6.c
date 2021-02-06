/* 6
编写一个程序打印一个表格，
每一行打印一个整数、该数的平方、该数的立方。
要求用户输入表格的上下限。
使用一个for循环。

*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int lowerBound, upperBound;
    printf("Please enter a lowerbound: ");
    scanf("%d", &lowerBound);
    printf("Please enter a upperbound: ");
    scanf("%d", &upperBound);
    printf("n\tn^2\tn^3\n");
    for(int i = lowerBound; i <= upperBound; i++) {
        printf("%d\t%d\t%d\n", i, i * i, i * i * i);
    }
    return 0;
}
