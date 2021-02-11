/* 4
编写一个程序，按顺序在屏幕上显示命令行中列出的所有文件。
使用argc控制循环。

*/ 

#include <stdio.h>
#include <stdlib.h>

void printFile(char const *);

int main(int argc, char const *argv[])
{
    int i;
    for(i = 1; i < argc; i++) {
        printf("Now, printing file \"%s\":\n", argv[i]);
        printFile(argv[i]);
    }
    return 0;
}

void printFile(char const *filename) {
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Can't open %s\n", filename); 
        exit(EXIT_FAILURE);
    }
    char ch;
    while((ch = getc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}