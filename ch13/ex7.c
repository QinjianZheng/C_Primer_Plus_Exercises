/* 7
编写一个程序打开两个文件。
可以使用命令行参数或提示用户输入文件名。
a.该程序以这样的顺序打印:
    打印第1个文件的第1行，
    第2个文件的第1行，
    第1个文件的第2行，
    第2个文件的第2行，
    以此类推，打印到行数较多文件的最后一行。
b.修改该程序，把行号相同的行打印成一行。
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_LINE    100
void print2FilesA(FILE *, FILE *);
void print2FilesB(FILE *, FILE *);

int main(int argc, char const *argv[])
{
    FILE *f1, *f2;
    if(argc < 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    assert((f1 = fopen(argv[1], "r")) != NULL);
    assert((f2 = fopen(argv[2], "r")) != NULL);
    
    print2FilesA(f1, f2);
    assert((f1 = fopen(argv[1], "r")) != NULL);
    assert((f2 = fopen(argv[2], "r")) != NULL);
    print2FilesB(f1, f2);
    fclose(f1);
    fclose(f2);
    return 0;
}

// 交替输出
void print2FilesA(FILE *f1, FILE *f2) {
    char line1[MAX_LINE];
    char line2[MAX_LINE];
    char *p1, *p2;

    int over1 = 0;
    int over2 = 0;
    while(1) {
        if(!over1) {
            p1 = fgets(line1, MAX_LINE, f1);
            if(p1 != NULL) {
                fputs(line1, stdout);
            } else {
                over1 = 1;
                printf("--------------file 1 is over-----------------\n");
            }
        }
        if(!over2) {
            p2 = fgets(line2, MAX_LINE, f2); 
            if(p2 != NULL) {
                fputs(line2, stdout);
            } else {
                over2 = 1;
                printf("--------------file 2 is over-----------------\n");

            }
        }
        if(over1 && over2) {
            break;
        }
        
    }
}
void print2FilesB(FILE *f1, FILE *f2) {
    char line1[MAX_LINE];
    char line2[MAX_LINE];
    char *p1, *p2;
    char *find; 
    int over1 = 0;
    int over2 = 0;
    while(1) {
        if(!over1) {
            p1 = fgets(line1, MAX_LINE, f1);
            if((find = strchr(line1, '\n')) != NULL) {
                *find = '\0';
            }
            if(p1 != NULL) {
                fputs(line1, stdout);
                printf("   <-|->   ");
            } else {
                over1 = 1;
                printf("--------------file 1 is over-----------------\n");
            }
        }
        if(!over2) {
            p2 = fgets(line2, MAX_LINE, f2); 
            if(p2 != NULL) {
                fputs(line2, stdout);
            } else {
                over2 = 1;
                printf("--------------file 2 is over-----------------\n");

            }
        }
        if(over1 && over2) {
            break;
        }
    }
}