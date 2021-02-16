/* 2
假设list.h(程序清单17.3)使用下面的list定义: 
typedef struct list {
    Node * head;  // 指向list的开头
    Node * end;   // 指向list的末尾
} List;

重写 list.c(程序清单 17.5)中的函数以适应新的定义，
并通过 films.c(程序清单 17.4)测试最终的代码。

*/ 



#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"



/*局部函数原型*/
static void CopyToNode(Item item, Node * pnode); /* 接口函数 */
/* 把链表设置为空 */
void InitializeList(List * plist) {
    plist->head = NULL;
    plist->end = NULL;
}

/* 如果链表为空，返回true */ 
bool ListIsEmpty(const List * plist) {
    if (plist->head == NULL)
        return true;
    else
        return false;
}

/* 如果链表已满，返回true */

bool ListIsFull(const List * plist) {
    Node * pt;
    bool full;
    pt = (Node *)malloc(sizeof(Node)); 
    if (pt == NULL) 
        full = true;
    else
        full = false; 
    free(pt); 
    return full;
}

/* 返回节点的数量 */
unsigned int ListItemCount(const List * plist) {
    unsigned int count = 0;
    Node * pnode = plist->head;  /* 设置链表的开始 */ 
    while (pnode != NULL) {
        ++count;
        pnode = pnode->next; /* 设置下一个节点 */
    }
    return count;
}
/* 创建储存项的节点，并将其添加至由plist指向的链表末尾(较慢的实 现)*/
bool AddItem(Item item, List * plist) {
    Node * pnew;
    Node * scan = plist->end;
    pnew = (Node *) malloc(sizeof(Node)); 
    if (pnew == NULL)
        return false;  /* 失败时退出函数 */ 
    CopyToNode(item, pnew); 
    pnew->next = NULL;
    if (scan == NULL) {   /* 空链表，所以把 */ 
        plist->head = pnew;    /* pnew放在链表的开头 */ 
    }
    else {
        scan->next = pnew;   /* 把pnew添加到链表的末尾 */
    }
    plist->end = pnew; // 新结点为链表的末尾
    return true;
}
/* 访问每个节点并执行pfun指向的函数 */
void Traverse(const List * plist, void(*pfun)(Item item)) {
    Node * pnode = plist->head;  /* 设置链表的开始 */ 
    while (pnode != NULL) {
        (*pfun)(pnode->item); /* 把函数应用于链表中的项 */ 
        pnode = pnode->next; /* 前进到下一项 */
    }
}
/* 释放由malloc()分配的内存 */
/* 设置链表指针为NULL   */
void EmptyTheList(List * plist) {
    Node * psave;
    while (plist->head != NULL) {
        psave = plist->head->next;  /* 保存下一个节点的地址  */ 
        free(plist->head);       /* 释放当前节点     */ 
        plist->head = psave;      /* 前进至下一个节点   */ 
    }

}
/*局部函数定义*/
/* 把一个项拷贝到节点中 */
static void CopyToNode(Item item, Node * pnode) {
    pnode->item = item; /* 拷贝结构 */
}