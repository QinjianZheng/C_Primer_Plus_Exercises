/* 10
编写一个函数接受一个字符串作为参数，并删除字符串中的空格。 
在一个程序中测试该函数，使用循环读取输入行，直到用户输入一行空行。 
该程序应该应用该函数只每个输入的字符串，并显示处理后的字符串。
*/ 

#include <stdio.h>
#include <string.h>
#define MAX_LINE    100

void trim(char *);
void trimV2(char *string);

int main(int argc, char const *argv[])
{
    char string[MAX_LINE];
    char *find;
    do
    {
        printf("Please enter a string: ");
        fgets(string, MAX_LINE, stdin);
        if((find = strchr(string, '\n')) != NULL) {
            *find = '\0';
        }
        printf("%s\n", string);
        trim(string);
        printf("%s\n", string);
    } while (*string != '\n');
    
    return 0;
}

// 有问题
void trim(char *string) {
    char *p = string;
    while(*p != '\0') {
        if(*p == ' ') {
            
            while(*p != '\0') {
                *p = *(p + 1);
                p++;
            }
        }
        string++;
        p = string;
    }
}

void trimV2(char *string) {
    char *head = string;
    int count = 0;
    while(*string != '\0') {
        if(*string != ' ') {
            *head++ = *string++;
        } else {
            string++;
            count ++;
        }
    }
    while(count --) {
        *head ++ = '\0';
    }
}