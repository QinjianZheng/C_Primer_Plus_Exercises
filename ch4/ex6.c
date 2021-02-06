/* 6

编写一个程序，先提示用户输入名，然后提示用户输入姓。
在一行打印用户输入的名和姓，下一行分别打印名和姓的字母数。
字母数要与相应名和姓的结尾对齐，如下所示:
Melissa Honeybee
      7        8
接下来，再打印相同的信息，但是字母个数与相应名和姓的开头对齐，
如下所示:
Melissa Honeybee
7       8

*/

#include <stdio.h>
#include <string.h>
#define NAMESIZE    12

int main(int argc, char const *argv[])
{
    char firstname[NAMESIZE];
    char lastname[NAMESIZE];

    printf("First name: ");
    scanf("%s", firstname);
    printf("Last name: ");
    scanf("%s", lastname);
    printf("%s %s\n", firstname, lastname);

    printf("%*d %*d\n", (int)strlen(firstname), (int)strlen(firstname), (int)strlen(lastname), (int)strlen(lastname));

    printf("%s %s\n", firstname, lastname);
    printf("%-*d %-*d\n", (int)strlen(firstname), (int)strlen(firstname), (int)strlen(lastname), (int)strlen(lastname));

    return 0;
}
