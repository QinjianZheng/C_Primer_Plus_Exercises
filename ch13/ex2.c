/* 2

编写一个文件拷贝程序，该程序通过命令行获取原始文件名和拷贝文件名。
尽量使用标准I/O和二进制模式。
*/ 

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    int ch;      // 读取文件时，储存每个字符的地方 
    FILE *fp, *dest;   // “文件指针”
    if(argc < 3) {
        printf("Usage %s source destination\n", argv[0]);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        printf("Can't open %s\n", argv[1]); 
        exit(EXIT_FAILURE);
    }
    if((dest = fopen(argv[2], "wb")) == NULL) {
        printf("Can't open %s\n", argv[2]); 
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF) {
        putc(ch, dest); // 与 putchar(ch); 相同
    }
    fclose(fp);
    fclose(dest);
    return 0;
}
