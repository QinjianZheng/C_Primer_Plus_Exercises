/* 7 
修改第7章的编程练习8，用字符代替数字标记菜单的选项。
用q代替5 作为结束输入的标记。

*/

#include <stdio.h>
#define OVERTIME_HOUR_MUL 1.5
#define NORMAL_HOUR 40
#define FIRST_BUCKET  300
#define SECOND_BUCKET 450
#define RATE_LOWER_THAN_300    0.15
#define RATE_LOWER_THAN_450    0.20
#define RATE_HIGHER_THAN_450   0.25

int main(int argc, char const *argv[])
{
    int choice;
    int hour;
    float sararyRate;
    float sarary;
    float tax;
    char repeat;
    printf("*****************************************************************\n");
    printf("Enter the character corresponding to the desired pay rate or action: \n");
    printf("a) $8.75/hr\tb) $9.33/hr\nc) $10.00/hr\td) $11.20/hr\nq) quit\n");
    printf("*****************************************************************\n");
    while((choice = getchar()) != 'q') {
        repeat = 0;
        switch (choice)
        {
        case 'a':
            sararyRate = 8.75;
            break;
        case 'b':
            sararyRate = 9.33;
            break;
        case 'c':
            sararyRate = 10.00;
            break;
        case 'd':
            sararyRate = 11.2;
            break;
        default:
            printf("Incorrect input.\n");
            repeat = 1;
            break;
        }
        if(repeat) {
            continue;
        }
        printf("Your sarary rate is %.2f\n", sararyRate);
        printf("Please work hour per week: ");
        scanf("%d", &hour);
        getchar();
        if(hour <= NORMAL_HOUR) {
            sarary = sararyRate * hour;
        } else {
            sarary = sararyRate * (NORMAL_HOUR + (hour - NORMAL_HOUR) * OVERTIME_HOUR_MUL);
        }
        if(sarary <= FIRST_BUCKET) {
            tax = sarary * RATE_LOWER_THAN_300;
        } else if(sarary <= SECOND_BUCKET) {
            tax = FIRST_BUCKET * RATE_LOWER_THAN_300 + (sarary - FIRST_BUCKET) * RATE_LOWER_THAN_450;
        } else {
            tax = FIRST_BUCKET * RATE_LOWER_THAN_300 + \
                    (SECOND_BUCKET - FIRST_BUCKET) * RATE_LOWER_THAN_450 + \
                    (sarary - SECOND_BUCKET) * RATE_HIGHER_THAN_450;
        }

        printf("Total sarary: %.1f\nTotal tax: %.1f\nNet sarary: %1.f\n", sarary, tax, sarary - tax);
        printf("*****************************************************************\n");
        printf("Enter the character corresponding to the desired pay rate or action: \n");
        printf("a) $8.75/hr\tb) $9.33/hr\nc) $10.00/hr\td) $11.20/hr\nq) quit\n");
        printf("*****************************************************************\n");
    }
    printf("Done!\n");
    return 0;
}
