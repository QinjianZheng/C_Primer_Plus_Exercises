/* 11

编写一个函数，读入10个字符串或者读到EOF时停止。
该程序为用户提供一个有5个选项的菜单:
打印源字符串列表、
以ASCII中的顺序打印字符串、
按长度递增顺序打印字符串、
按字符串中第1个单词的长度打印字符串、
退出。
菜单可以循环显示，除非用户选择退出选项。
当然，该程序要能真正完成菜单中各选项的功能。

*/ 

#include <stdio.h>
#define SIZE        10
#define MAX_LINE    100

int getChoice(void);
void printList(char strings[][MAX_LINE], int);
// void printAsciiOrder(void);
// void printLenOrder(void);
// void printFirstWordOrder(void);

int main(int argc, char const *argv[])
{
    int count = 0;
    char ch;
    int input;
    int i = 0;
    char strings[SIZE][MAX_LINE] = {{'\0'}};
    while((ch = getchar()) != EOF && count < SIZE) {
        if(ch == '\n') {
            strings[count][i] = ch;
            count ++;
            i = 0;
        } else {
            strings[count][i] = ch;
            i++;
        }
    }
    while((ch = getchar()) != EOF && ch != '\n');
    while((input = getChoice()) != 5) {
        switch(input) {
            case 1:
                printList(strings, count);
                break;
            // case 2:
            //     printAsciiOrder();
            //     break;
            // case 3:
            //     printLenOrder();
            //     break;
            // case 4:
            //     printFirstWordOrder();
            //     break;
            default:
                printf("Incorrect command...\n");
                break;
        }
    }
    printf("Done.\n");
    return 0;
}

int getChoice(void) {
    printf("请输入命令：\n");
    printf("1)打印源字符串列表\n");
    printf("2)以ASCII中的顺序打印字符串\n");
    printf("3)按长度递增顺序打印字符串\n");
    printf("4)按字符串中第1个单词的长度打印字符串\n");
    printf("5)退出\n");
    int input;
    scanf("%d", &input);
    return input;
}


void printList(char strings[][MAX_LINE], int count) {
    for(int i = 0; i < count; i++) {
        printf("%s", strings[i]);
    }
}
