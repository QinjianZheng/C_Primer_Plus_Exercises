/* 8

编写一个程序，要求用户输入两个浮点数，
并打印两数之差除以两数乘积的结果。
在用户输入非数字之前，程序应循环处理用户输入的每对值

*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    float n1, n2;
    
    do
    {
        printf("Please enter the first number: ");
        if((scanf("%f", &n1)) != 1) {
            break;
        }
        
        printf("Please enter the second number: ");
        if((scanf("%f", &n2)) != 1) {
            break;
        }
        float diff = n1 - n2;
        float product = n1 * n2;
        printf("diff = %f | product = %f\n", diff, product);
    } while (1);
    

    return 0;
}
