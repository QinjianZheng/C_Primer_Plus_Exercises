/* 9

修改练习8，使用一个函数返回计算的结果。

*/
#include <stdio.h>

void calculate(float, float, float[]);

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
        float result[2];
        calculate(n1, n2, result);

        printf("diff = %f | product = %f\n", result[0], result[1]);
    } while (1);
    

    return 0;
}

void calculate(float n1, float n2, float result[]) {


    result[0] = n1 - n2;
    result[1] = n1 * n2;


}
