/* 6
使用命令行参数的程序依赖于用户的内存如何正确地使用它们。
重写程序清单13.2中的程序，不使用命令行参数，而是提示用户输入所需信息。
*/ 

// reducto.c –把文件压缩成原来的1/3!
#include <stdio.h>
#include <stdlib.h>  // 提供 exit()的原型
#include <string.h>  // 提供 strcpy()、strcat()的原型 
#define LEN 40
int main(int argc, char *argv []) {
    FILE *in, *out;  // 声明两个指向 FILE 的指针
    int ch;
    char name[LEN];  // 储存输出文件名
    int count = 0;
    printf("Please enter the filename you want to reduce in size: ");
    scanf("%s", name);
    // 设置输入
    if ((in = fopen(name, "r")) == NULL) {
        fprintf(stderr, "I couldn't open the file \"%s\"\n",
        name);
        exit(EXIT_FAILURE);
    }
    // 设置输出
    strcat(name, ".red");        // 在文件名后添加.red 
    if ((out = fopen(name, "w")) == NULL) {          // 以写模式打开文件
        fprintf(stderr, "Can't create output file.\n"); 
        exit(3);
    }
    // 拷贝数据
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);// 打印3个字符中的第1个字符
    // 收尾工作
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");
    return 0;
}
