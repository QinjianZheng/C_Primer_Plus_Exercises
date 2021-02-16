/* 5
编写一个程序，提示用户输入一个字符串。
然后该程序把该字符串的字符逐个压入一个栈(参见复习题5)，
然后从栈中弹出这些字符，并显示它们。
结果显示为该字符串的逆序。

*/ 

#include <stdio.h>
#include <string.h>
#include "stack.h"
#define SIZE    1024

int main(int argc, char const *argv[])
{
    Stack s;
    InitializeStack(&s);
    printf("Please enter a string.\n");
    char string[SIZE];
    char *find;
    fgets(string, SIZE, stdin);
    find = strchr(string, '\n');
    if(find) {
        *find = '\0';
    }
    char *p = string;
    while(*p != '\0') {
        if(StackIsFull(&s)) {
            break;
        }
        Push(*p, &s);
        p++;
    }
    char temp;
    while(!StackIsEmpty(&s)) {
        Pop(&temp, &s);
        printf("%c", temp);
    }
    return 0;
}
