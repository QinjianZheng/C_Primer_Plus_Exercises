/* 2
编写一个程序，提示用户输入名和姓，并执行一下操作: 
a.打印名和姓，包括双引号; 
b.在宽度为20的字段右端打印名和姓，包括双引号; 
c.在宽度为20的字段左端打印名和姓，包括双引号; 
d.在比姓名宽度宽3的字段中打印名和姓。
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

    printf("\"%s, %s\"\n", firstname, lastname);
    printf("\"%20s, %s\"\n", firstname, lastname);
    printf("\"%s, %-20s\"\n", firstname, lastname);
    int width = strlen(firstname) + 3;
    printf("\"%*s, %s\"\n", width, firstname, lastname);
    return 0;
}
