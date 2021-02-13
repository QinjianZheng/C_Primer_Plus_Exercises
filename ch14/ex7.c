/* 7

修改程序清单 14.14，从文件中读取每条记录并显示出来，
允许用户删除记录或修改记录的内容。
如果删除记录，把空出来的空间留给下一个要读入的记录。
要修改现有的文件内容，必须用"r+b"模式，而不是"a+b"模式。
而且，必须更加注意定位文件指针，防止新加入的记录覆盖现有记录。 
最简单的方法是改动储存在内存中的所有数据，然后再把最后的信息写入文件。
跟踪的一个方法是在book结构中添加一个成员表示是否该项被删除。

*/ 

/* booksave.c -- 在文件中保存结构中的内容 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10     /* 最大书籍数量 */ 
struct book {       /* 建立 book 模板 */ 
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    int toDelete;
};
char * s_gets(char * st, int n);

int isIn(struct book *, int n, char *);

int main(void) {
    struct book library[MAXBKS]; /* 结构数组 */
    int count = 0;
    int index, filecount;
    FILE * pbooks;
    char delete[MAXTITL];
    char amend[MAXTITL];
    int toDelete, toAmend;
    int size = sizeof(struct book);
    if ((pbooks = fopen("book.dat", "a+b")) == NULL) {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }
    rewind(pbooks);      /* 定位到文件开始 */
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1) {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n", library[count].title, 
                                    library[count].author, 
                                    library[count].value);
        library[count].toDelete = 0;
        count++;
    }
    filecount = count;
    if (count == 0) {
        fputs("The book.dat file is empty.\n", stderr);
        exit(2);
    }
    puts("Please enter book title you want to delete.");
    puts("Press [enter] at the start of a line to stop.");
    while (count > 0 && s_gets(delete, MAXTITL) != NULL
    && delete[0] != '\0') {
        if((toDelete = isIn(library, count, delete)) >= 0) {
            library[toDelete].toDelete = 1;
        }
        count --;
        if(count > 0) {
            puts("Enter the next title you want to delete.");
        }
    }
    puts("Please enter book title you want to amend.");
    puts("Press [enter] at the start of a line to stop.");
    char ch;
    while (s_gets(amend, MAXTITL) != NULL
    && amend[0] != '\0') {
        if((toAmend = isIn(library, count, amend)) >= 0 && library[toAmend].toDelete == 0) {
            puts("Press 'y' if you want to amend the author, others to skip.");
            if(scanf(" %c", &ch) == 1 && ch == 'y') {
                puts("Now enter the new author."); 
                s_gets(library[toAmend].author, MAXAUTL); 
            }
            puts("Press 'y' if you want to amend the value, others to skip");
            if(scanf(" %c", &ch) == 1 && ch == 'y') {
                puts("Now enter the new author."); 
                scanf("%f", &library[toAmend].value); 
            }
        }
        while (getchar() != '\n') 
            continue;     /* 清理输入行 */ 
        
        puts("Enter the next title you want to amend."); 

    }
    if (count > 0) {
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++) 
        if(library[index].toDelete == 0) {
            printf("%s by %s: $%.2f\n", library[index].title, 
                                        library[index].author, 
                                        library[index].value);
            // fwrite(&library[filecount], size, count - filecount, pbooks);
        }
    }
    else
        puts("No books? Too bad.\n"); 
    puts("Bye.\n"); 
    fclose(pbooks);
    return 0;
}
char * s_gets(char * st, int n) {
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');  // 查找换行符
        if (find)       // 如果地址不是 NULL， 
            *find = '\0';     // 在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue;   // 清理输入行
    }
    return ret_val;
}

int isIn(struct book *library, int n, char *delete) {
    for(int i = 0; i < n; i++) {
        if(strcmp(library[i].title, delete) == 0) {
            return i;
        }
    }
    return -1;
}
