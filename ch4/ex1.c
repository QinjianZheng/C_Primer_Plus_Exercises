/* 1

编写一个程序，提示用户输入名和姓，然后以“名,姓”的格式打印出来。

*/

#include <stdio.h>
#define NAMESIZE    12


int main(int argc, char const *argv[])
{
    char firstname[NAMESIZE];
    char lastname[NAMESIZE];

    printf("First name: ");
    scanf("%s", firstname);
    printf("Last name: ");
    scanf("%s", lastname);

    printf("%s, %s\n", firstname, lastname);
    return 0;
}
