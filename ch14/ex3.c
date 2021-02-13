/* 3

修改程序清单 14.2 中的图书目录程序，
使其按照输入图书的顺序输出图书的信息，
然后按照标题字母的升序输出图书的信息，
最后按照价格的升序输出图书的信息。

*/ 

/* manybook.c -- 包含多本书的图书目录 */ 
#include <stdio.h>
#include <string.h>
#define MAXTITL  40
#define MAXAUTL  40
#define MAXBKS 100    /* 书籍的最大数量 */ 
struct book {
          /* 简历 book 模板  */ 
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char * s_gets(char * st, int n);
int titleCmp(const void *, const void *);
int valueCmp(const void *, const void *);

typedef int Cmp (const void *, const void *);
void sortBook(struct book *, int, Cmp *);

int main(void) {
    struct book library[MAXBKS];  /* book 类型结构的数组 */ 
    int count = 0;
    int index;
    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
    && library[count].title[0] != '\0') {
        printf("Now enter the author.\n"); 
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n"); 
        scanf("%f", &library[count++].value); 
        while (getchar() != '\n')
            continue;   /* 清理输入行*/
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    // 输出 按照输入顺序
    if (count > 0) {
        printf("\nHere is the list of your books:\n");
        for (index = 0; index < count; index++) 
            printf("%s by %s: $%.2f\n", library[index].title, 
                                        library[index].author, 
                                        library[index].value);
        printf("\nHere is the list of your books sorted by title:\n");
        sortBook(library, count, titleCmp);
        for (index = 0; index < count; index++) 
            printf("%s by %s: $%.2f\n", library[index].title, 
                                        library[index].author, 
                                        library[index].value);
        printf("\nHere is the list of your books sorted by value:\n");
        sortBook(library, count, valueCmp);
        for (index = 0; index < count; index++) 
            printf("%s by %s: $%.2f\n", library[index].title, 
                                        library[index].author, 
                                        library[index].value);
    } else
        printf("No books? Too bad.\n");
    return 0;
}

char * s_gets(char * st, int n) {
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');  // 查找换行符
        if (find)          // 如果地址不是 NULL， 
            *find = '\0';     // 在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue;     // 处理输入行中剩余的字符
    }
    return ret_val;
}


int titleCmp(const void *record, const void *key) {
    const struct book *r = record;
    const struct book *k = key;
    return strcmp(r->title, k->title);
}

int valueCmp(const void *record, const void *key) {
    const struct book *r = record;
    const struct book *k = key;
    return (r->value - k->value);
}

void sortBook(struct book *library, int n, Cmp *cmp) {
    int i, j;
    struct book temp;
    for(i = 1; i < n; i++) {
        temp = library[i];
        j = i - 1;
        while(j >= 0 && cmp(&library[j], &temp) > 0) {
            library[j+1] = library[j];
            j--;
        }
        library[j+1] = temp;
    }
}