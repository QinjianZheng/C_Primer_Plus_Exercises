/* 10
编写一个程序，要求用户输入一个上限整数和一个下限整数，
计算 从上限到下限范围内所有整数的平方和，并显示计算结果。
然后程序继续提 示用户输入上限和下限整数，并显示结果，
直到用户输入的上限整数小于下 限整数为止。

程序的运行示例如下:

Enter lower and upper integer limits: 5 9 
The sums of the squares from 25 to 81 is 255 
Enter next set of limits: 3 25 
The sums of the squares from 9 to 625 is 5520 
Enter next set of limits: 5 5
Done
*/

#include <stdio.h>
#include <assert.h>
int main(int argc, char const *argv[])
{
    int upperBound, lowerBound;
    printf("Enter lower and upper integer limits: ");
    assert(scanf("%d %d", &lowerBound, &upperBound) == 2);
    while(lowerBound < upperBound) {
        int sum = 0;
        int lowerBoundSquared = lowerBound * lowerBound;
        int upperBoundSquared = upperBound * upperBound;
        for(int i = lowerBound; i <= upperBound; i++) {
            sum += i * i;
        }
        printf("The sums of the squares from %d to %d is %d\n",
                lowerBoundSquared, upperBoundSquared, sum);
        printf("Enter lower and upper integer limits(q for quit): ");
        if(scanf("%d %d", &lowerBound, &upperBound) != 2) {
            break;
        }
    } 
    printf("Done\n");
    return 0;
}
