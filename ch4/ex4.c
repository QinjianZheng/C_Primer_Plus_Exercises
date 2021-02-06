/* 4
编写一个程序，提示用户输入身高(单位:英寸)和姓名，
然后以下面的格式显示用户刚输入的信息:
Dabney, you are 6.208 feet tall

*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char name[12];
    float ht;
    printf("Enter you name: ");
    scanf("%s", name);
    printf("How tall? ");
    scanf("%f", &ht);

    printf("%s, you are %.3f feet tall\n", name, ht);

    return 0;
}
