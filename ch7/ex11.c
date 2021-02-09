/* 11
ABC 邮购杂货店出售的:
洋蓟售价为 2.05 美元/磅，artichoke
甜菜售价为 1.15 美元/磅，beet
胡萝卜售价为 1.09美元/磅。carrot
在添加运费之前，100美元的订单有 5%的打折优惠。
少于或等于5磅的订单收取6.5美元的运费和包装费，
5磅~ 20磅的订单收取14美元的运费和包装费，
超过20磅的订单在14美元的基础上每续重1磅增加0.5美元。

编写一个程序，在循环中用switch语句实现用户输入不同的字母时有不同的响应，
即输入:
a的响应是让用户输入洋蓟的磅数，
b是甜菜的磅数，
c是胡萝卜的磅数，
q是退出订购。
程序要记录累计的重量。
即，如果用户输入 4 磅的甜菜，然后输入 5磅的甜菜，程序应报告9磅 的甜菜。
然后，该程序要计算货物总价、折扣(如果有的话)、运费和包装 费。

随后，程序应显示所有的购买信息:
物品售价、订购的重量(单位: 磅)、订购的蔬菜费用、
订单的总费用、折扣(如果有的话)、运费和包装费，以及所有的费用总额。


*/

#include <stdio.h>
#define ARTICHOKE_PRICE 2.05
#define BEET_PRICE 1.15
#define CARROT_PRICE    1.09
#define DISCOUNT_OVER_100USD  0.05
#define FIRST_BUCKET 5
#define FIRST_DELIVERY 6.5
#define SECOND_BUCKET 20
#define SECOND_DELIVERY 14
#define PROG_RATE_PER_POUND 0.5

int main(int argc, char const *argv[])
{
    char ch;
    int artichokeW = 0;
    int beetW = 0;
    int carrotW = 0;
    int input;
    do {
        printf("Command:\n");
        printf("a) artichoke weight input\n");
        printf("b) beet weight input\n");
        printf("c) carrot weight input\n");
        printf("q) quit\n");
    
        scanf(" %c", &ch);
        switch (ch)
        {
        case 'a':
            printf("Enter the weight for artichoke: ");
            scanf("%d", &input);
            artichokeW += input;
            break;
        case 'b':
            printf("Enter the weight for beet: ");
            scanf("%d", &input);
            beetW += input;
            break;
        case 'c':
            printf("Enter the weight for carrot: ");
            scanf("%d", &input);
            carrotW += input;
            break;
        case 'q':
            printf("Quit ordering...\n");
            break;
        default:
            printf("Incorrect input\n");
        }
    } while(ch != 'q');

    printf("The following is your order: \n");
    float artichokeA = artichokeW * ARTICHOKE_PRICE;
    float beetA = beetW * BEET_PRICE;
    float carrotA = carrotW * CARROT_PRICE;
    printf("Artichock price: %.2f | weight: %d | money amount: %f\n",
            ARTICHOKE_PRICE, artichokeW, artichokeA);
    printf("Beet price: %.2f | weight: %d | money amount: %f\n",
            BEET_PRICE, beetW, beetA);
    printf("Carrot price: %.2f | weight: %d | money amount: %f\n",
            CARROT_PRICE, carrotW, carrotA);
    float totalA  = artichokeA + beetA + carrotA;
    float discount = 0;
    if(totalA >= 100) {
        discount = totalA * DISCOUNT_OVER_100USD;
    }
    int totalW = artichokeW + beetW + carrotW;
    float deliveryFee = 0;
    if(totalW <= FIRST_BUCKET) {
        deliveryFee = FIRST_DELIVERY;
    } else if(totalW <= SECOND_BUCKET) {
        deliveryFee = SECOND_DELIVERY;
    } else {
        deliveryFee = SECOND_DELIVERY + (totalW - SECOND_BUCKET) * PROG_RATE_PER_POUND;
    }
    printf("Total amount: %f\n", totalA);
    if(discount > 0) {
        printf("Discount: %f\n", discount);
        
    }
    printf("Delivery fee: %f\n", deliveryFee);
    float total = totalA - discount + deliveryFee;
    printf("Total amount including discount and delivery: %f\n", total);
    return 0;
}




