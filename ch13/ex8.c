/* 8

编写一个程序，以一个字符和任意文件名作为命令行参数。
如果字符后面没有参数，该程序读取标准输入;
否则，程序依次打开每个文件并报告每个文件中该字符出现的次数。
文件名和字符本身也要一同报告。
程序应包含错误检查，以确定参数数量是否正确和是否能打开文件。
如果无法打开文件，程序应报告这一情况，然后继续处理下一个文件。
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define NAMESIZE    100

int countChar(const char *, char);

int main(int argc, char const *argv[])
{
    char filename[BUFSIZ];
    // char *files[NAMESIZE];
    if(argc < 2) {
        printf("Usage %s character file1 file2 file3 ...\n", argv[0]);
    } else if(argc < 3) {
        printf("please enter the filename(s): (e.g. file1 file2 file3...): ");
        assert(fgets(filename, BUFSIZ, stdin) != NULL);
        char *p = filename;
        char *t = p;
        while(*p != '\0') {
            if(*p == ' ' || *p == '\n') {
                *p = '\0';
                // process the files with name "t"
                printf("file \"%s\" has %d \'%c\'\n", t, countChar(t, argv[1][0]), argv[1][0]);
                p++;
                t = p;
            } else {
                p++;
            }
        }
    } else {
        for(int i = 2; i < argc; i++) {
            printf("file \"%s\" has %d \'%c\'\n", argv[i], countChar(argv[i], argv[1][0]), argv[1][0]);
        }
    }
    return 0;
}

int countChar(const char *filename, char ch) {
    int count = 0;
    FILE *fp = fopen(filename, "r");
    assert(fp != NULL);
    char c;
    while((c = getc(fp)) != EOF) {
        if(c == ch) {
            count ++;
        }
    }
    return count;
}