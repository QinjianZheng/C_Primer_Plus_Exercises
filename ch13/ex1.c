/* 1

修改程序清单13.1中的程序，要求提示用户输入文件名，并读取用户
输入的信息，不使用命令行参数。
*/ 

/* count.c -- 使用标准 I/O */
#include <stdio.h>
#include <stdlib.h>  // 提供 exit()的原型 
#define SIZE    12
int main(int argc, char *argv []) {
    int ch;      // 读取文件时，储存每个字符的地方 
    FILE *fp;   // “文件指针”
    unsigned long count = 0;
    char filename[SIZE];
    printf("Please enter a filename: ");
    scanf("%s", filename);
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Can't open %s\n", filename); 
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF) {
        putc(ch, stdout); // 与 putchar(ch); 相同
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", filename, count); 
    return 0;
}
