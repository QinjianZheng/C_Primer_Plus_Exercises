/* 10

1988年的美国联邦税收计划是近代最简单的税收方案。它分为4个类别，每个类别有两个等级。
下面是该税收计划的摘要(美元数为应征税的收入):

类别            税金
单身            <=17850 15%, > 28%
户主            <=23900 15%, > 28%
已婚，共有       <=29750 15%, > 28%
已婚，离异       <=14875 15%, > 28%

例如，一位工资为20000美元的单身纳税人，应缴纳税费 0.15×17850+0.28×(20000−17850)美元。
编写一个程序，让用户指定缴纳税金的种类和应纳税收入，然后计算税金。
程序应通过循环让用户可以多次输入。

*/

#include <stdio.h>
#include <stdlib.h>

#define  SINGLE_BASE  17850
#define  OWNER_BASE   23900
#define  JOINED_BASE  29750
#define  DIVORCED_BASE 14875
#define  BASE_RATE 0.15
#define  PROG_RATE 0.28

enum type {SINGLE, OWNER, JOINED, DIVORCED};

typedef enum type Type;

void showMenu(void);
void calculateTax(int);
int main(int argc, char const *argv[])
{
    Type type;
    int base;

    do {
        showMenu();
        scanf("%d", &type);
        switch (type)
        {
        case SINGLE:
            base = SINGLE_BASE;
            
            break;
        case OWNER:
            base = OWNER_BASE;
            break;
        case JOINED:
            base = JOINED_BASE;
            break;
        case DIVORCED:
            base = DIVORCED_BASE;
            break;
        default:
            printf("Incorrect input...\n");
            break;
        }
        calculateTax(base);
    } while(type != 4);
    
    return 0;
    
    
}

void showMenu(void) {
    printf("Choose the tax status:\n");
    printf("0) Single\n");
    printf("1) Owner\n");
    printf("2) Joined\n");
    printf("3) Divorced\n");
    printf("4) Quit\n");
}

void calculateTax(int base) {
    float tax;
    int sarary;
    printf("Please enter your sarary: ");
    scanf("%d", &sarary);

    if(sarary <= base) {
        tax = sarary * BASE_RATE;
    } else {
        tax = base * BASE_RATE + (sarary - base) * PROG_RATE;
    }
    printf("The base of your tax status is %d\n", base);
    printf("Your sarary: %d | Tax payable: %.2f\n", sarary, tax);
}