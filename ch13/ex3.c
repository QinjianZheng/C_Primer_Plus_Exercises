/* 3
编写一个文件拷贝程序，提示用户输入文本文件名，
并以该文件名作为原始文件名和输出文件名。
该程序要使用 ctype.h 中的 toupper()函数，
在写入到输出文件时把所有文本转换成大写。
使用标准I/O和文本模式。

*/ 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE    12
#define FILESIZE    2048
int main(int argc, char const *argv[])
{
    int ch;      // 读取文件时，储存每个字符的地方 
    char filename[SIZE];
    char file[FILESIZE];
    FILE *fp, *dest;   // “文件指针”
    printf("Please enter the source file: ");
    scanf("%s", filename);
    if ((fp = fopen(filename, "rb")) == NULL) {
        printf("Can't open %s\n", argv[1]); 
        exit(EXIT_FAILURE);
    }
    char *p = file;
    while ((ch = getc(fp)) != EOF) {
        *p = toupper(ch);
        p++;
    }
    *p = '\0';
    fclose(fp);
    if((dest = fopen(filename, "wb")) == NULL) {
        printf("Can't open %s\n", argv[2]); 
        exit(EXIT_FAILURE);
    }

    p = file;
    while(*p != '\0') {
        putc(*p, dest);
        p++;
    }   

    fclose(dest);
    return 0;
}
