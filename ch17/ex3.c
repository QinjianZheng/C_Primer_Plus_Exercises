/* 3

假设list.h(程序清单17.3)使用下面的list定义: 
#define MAXSIZE 100
typedef struct list
{
    Item entries[MAXSIZE]; // 内含项的数组
    int items;             // list中的项数
} List;
重写 list.c(程序清单 17.5)中的函数以适应新的定义，
并通过 films.c(程序清单 17.4)测试最终的代码。

*/ 

#include <stdio.h>
#include <stdlib.h>
#include "ex3.h"


/* 把链表设置为空 */
void InitializeList(List * plist) {
    plist->items = 0;
}

/* 如果链表为空，返回true */ 
bool ListIsEmpty(const List * plist) {
    if (plist->items == 0)
        return true;
    else
        return false;
}

/* 如果链表已满，返回true */

bool ListIsFull(const List * plist) {
    return plist->items == MAXSIZE;
}
/* 返回节点的数量 */
unsigned int ListItemCount(const List * plist) {
    return plist->items;
}
/* 创建储存项的节点，并将其添加至由plist指向的链表末尾(较慢的实 现)*/
bool AddItem(Item item, List * plist) {
    if(!ListIsFull(plist)) {
        plist->entries[plist->items] = item;
        plist->items++;
        return true;
    } else {
        return false;
    }
    

}
/* 访问每个节点并执行pfun指向的函数 */
void Traverse(const List * plist, void(*pfun)(Item item)) {
    int i;
    for(i = 0; i < plist->items; i++) {
        (*pfun) (plist->entries[i]);
    }
}
