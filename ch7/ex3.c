/* 3
编写一个程序，读取整数直到用户输入0。
输入结束后，程序应报告用户输入的偶数(不包括0)个数、这些偶数的平均值、输入的奇数个数及其奇数的平均值。


*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int ret;
    int evenCount = 0;
    int evenSum = 0;
    int oddCount = 0;
    int oddSum = 0;
    int num = 0;
    ret = scanf("%d", &num);
    while(num != 0) {
        if(num % 2 == 0) {
            evenCount ++;
            evenSum += num;
        } else {
            oddCount ++;
            oddSum += num;
        }

        ret = scanf("%d", &num);
    }
    float evenAverage = evenSum/evenCount;
    float oddAverage = oddSum/oddCount;
    printf("even#: %d | even average: %f\nodd#: %d | odd average: %f\n", 
            evenCount, evenAverage, oddCount, oddAverage);
    return 0;
}