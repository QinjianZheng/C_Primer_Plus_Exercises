/* 8

编写一个程序，显示一个提供加法、减法、乘法、除法的菜单。
获得用户选择的选项后，程序提示用户输入两个数字，然后执行用户刚才选择的操作。
该程序只接受菜单提供的选项。
程序使用float类型的变量储存用户输入的数字，如果用户输入失败，则允许再次输入。
进行除法运算时，如果用户输入0作为第2个数(除数)，程序应提示用户重新输入一个新值。
该程序的一个运行示例如下:
Enter the operation of your choice: 
a. add        s. subtract 
m. multiply   d. divide
q. quit
a
Enter first number: 22.4
Enter second number: one
one is not an number. 
Please enter a number, such as 2.5, -1.78E8, or 3: 1 
22.4 + 1 = 23.4
Enter the operation of your choice: 
a. add        s. subtract 
m. multiply   d. divide
q. quit
d
Enter first number: 18.4 
Enter second number: 0 
Enter a number other than 0: 0.2 
18.4 / 0.2 = 92 
Enter the operation of your choice: 
a. add        s. subtract 
m. multiply   d. divide
q. quit
q
Bye.
*/

#include <stdio.h>
#include <stdlib.h>

void showMenu(void);
float calculate(float, float, char);
char convertToSign(char);
float getNumber(void);

int main(int argc, char const *argv[])
{
    showMenu();
    char ch;
    float first, second;
    float result;
    while((ch = getchar()) != 'q') {
        printf("Enter first number: ");
        first = getNumber();
        printf("Enter second number: ");
        if(ch == 'd') {
            while((second = getNumber()) == 0) {
                printf("Enter a number other than 0: ");
            }
        } else {
            second = getNumber();
        }
        result = calculate(first, second, ch);
        printf("%.1f %c %.1f = %.1f\n", first, convertToSign(ch), second, result);
        // get rid of '\n' after scanf()
        while(getchar() != '\n') {
            continue;
        }
        showMenu();
    }
    printf("Done.\n");
    return 0;
}

void showMenu(void) {
    printf("Enter the operation of your choice:\n"); 
    printf("a. add        s. subtract\n");
    printf("m. multiply   d. divide\n");
    printf("q. quit\n");
}

float calculate(float n1, float n2, char ch) {
    float result = 0.0;
    switch (ch)
    {
    case 'a':
        result = n1 + n2;
        break;
    case 's':
        result = n1 - n2;
        break;
    case 'm':
        result = n1 * n2;
        break;
    case 'd':
        result = n1 / n2;
        break;
    default:
        break;
    }
    return result;
}

char convertToSign(char ch) {
    char sign = '\0';
    switch (ch)
    {
    case 'a':
        sign = '+';
        break;
    case 's':
        sign = '-';
        break;
    case 'm':
        sign = '*';
        break;
    case 'd':
        sign = '/';
        break;
    default:
        break;
    }
    return sign;
}

float getNumber(void) {
    float input;
    char ch;
    while((scanf("%f", &input) != 1)) {
        while((ch = getchar()) != '\n') {
            putchar(ch);
        }
        printf(" is not an number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
    }
    return input;
}