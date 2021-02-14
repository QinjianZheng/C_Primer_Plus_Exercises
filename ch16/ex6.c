/* 6
修改程序清单16.17，使用struct names元素(在程序清单16.17后面的 讨论中定义过)，
而不是double类型的数组。使用较少的元素，并用选定的名字显式初始化数组。

*/ 

/* qsorter.c -- 用 qsort()排序一组数字 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 10
#define LEN 12

typedef struct name {
    char first[LEN];
    char last[LEN];
} Name;

void fillarray(Name [], int n);
void showarray(const Name  [], int n);
int mycomp(const void * p1, const void * p2); 

int main(void) {
    Name names[NUM];
    fillarray(names, NUM);
    puts("Random list:");
    showarray(names, NUM);
    qsort(names, NUM, sizeof(Name), mycomp); 
    puts("\nSorted list:");
    showarray(names, NUM);
    return 0;
}
void fillarray(Name ar [], int n) {
    int index = 0;
    while(index < n) {
        printf("Please enter the first name and last name: ");
        if(scanf("%s %s", ar[index].first, ar[index].last) == 2) {
            index++;
        }
    }
        
}
void showarray(const Name ar [], int n) {
    int index;
    for (index = 0; index < n; index++) {
        printf("%s, %s\n", ar[index].last, ar[index].first);
    }
}
/* 按从小到大的顺序排序 */
int mycomp(const void * p1, const void * p2) {
    /* 要使用指向double的指针来访问这两个值 */
    const Name * a1 = (const Name *)  p1;
    const Name * a2 = (const Name *)  p2;
    int res;
    res = strcmp(a1->last, a2->last); /* 比较 */
    if (res != 0)
        return res;
    else /* 如果同姓，则比较名 */
        return strcmp(a1->first, a2->first);
}

