/* 10
编写一个程序打开一个文本文件，通过交互方式获得文件名。
通过一个循环，提示用户输入一个文件位置。
然后该程序打印从该位置开始到下一个换行符之前的内容。
用户输入负数或非数值字符可以结束输入循环

*/ 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char const *argv[])
{
    char filename[BUFSIZ];
    printf("Please enter a filename: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");
    assert(fp != NULL);
    long pos;
    char ch;
    fseek(fp, 0L, SEEK_END);
    long last = ftell(fp);
    printf("Please enter the start position: ");
    while(scanf("%ld", &pos) == 1 && pos >= 0) {
        if(pos >= last) {
            printf("You have gone beyong the file, try 0 to %ld.\n", last-1);
        } else {
            fseek(fp, pos, SEEK_SET);
            while((ch = getc(fp)) != '\n') {
                putc(ch, stdout);
            }
            putchar('\n');
        }
        printf("Please enter the start position: ");
    }
    return 0;
}

