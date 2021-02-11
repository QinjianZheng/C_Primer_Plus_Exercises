/* 16
编写一个程序读取输入，直至读到文件结尾，
然后把字符串打印出来。
该程序识别和实现下面的命令行参数:
-p     按原样打印
-u     把输入全部转换成大写
-l     把输入全部转换成小写
*/ 

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE    2000


int main(int argc, char const *argv[])
{
    char string[SIZE];
    int i = 0;
    char ch;
    printf("Enter a string: ");
    while((ch = getchar()) != EOF) {
        string[i] = ch;
        i++;
    }
    if(argc == 1 || strcmp(argv[1], "-p") == 0) {
        printf("%s", string);
    } else if(strcmp(argv[1], "-l") == 0) {
        char *p = string;
        while(*p != '\0') {
            printf("%c", tolower(*p));
            p++;
        }
    } else if(strcmp(argv[1], "-u") == 0) {
        char *p = string;
        while(*p != '\0') {
            printf("%c", toupper(*p));
            p++;
        }
    }
    return 0;
}