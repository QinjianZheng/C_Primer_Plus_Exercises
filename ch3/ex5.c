/* 5
一年大约有3.156×10^7秒。
编写一个程序，提示用户输入年龄，然后显示该年龄对应的秒数。

*/

#include <stdio.h>
#define SECONDS_PER_YEAR 3.156E+7
int main(int argc, char const *argv[])
{
    int age;
    printf("Tell me your age: ");
    scanf("%d", &age);
    printf("You have lived for %.0f seconds.\n", age * SECONDS_PER_YEAR);
    return 0;
}
