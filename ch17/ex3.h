/* list.h -- 简单链表类型的头文件 */ 
#ifndef LIST_H_ 
#define LIST_H_
#include <stdbool.h> /* C99特性      */
/* 特定程序的声明 */
#define TSIZE   45 /* 储存电影名的数组大小  */ 
#define MAXSIZE 100
struct film {
    char title[TSIZE];
    int rating;
};
/*一般类型定义*/
typedef struct film Item;


typedef struct list
{
    Item entries[MAXSIZE]; // 内含项的数组
    int items;             // list中的项数
} List;
/*函数原型*/
/* 操作:   初始化一个链 表                       */
/* 前提条件:  plist指向一个链 表                     */
/* 后置条件:  链表初始化为 空                       */
void InitializeList(List * plist);
/* 操作:   确定链表是否为空定义，plist指向一个已初始化的链表        */
/* 后置条件:  如果链表为空，该函数返回true;否则返回false         */
bool ListIsEmpty(const List *plist);
/* 操作:   确定链表是否已满，plist指向一个已初始化的链表         */
/* 后置条件:  如果链表已满，该函数返回真;否则返回假             */
bool ListIsFull(const List *plist);
/* 操作:   确定链表中的项数, plist指向一个已初始化的链表         */
/* 后置条件: 该函数返回链表中的项数                   */
unsigned int ListItemCount(const List *plist);

/* 操作:   在链表的末尾添加 项                     */
/* 前提条件:  item是一个待添加至链表的项, plist指向一个已初始化 的链表    */
/* 后置条件:  如果可以，该函数在链表末尾添加一个项，且返回 true;否则返回false */
bool AddItem(Item item, List * plist);
/* 操作:   把函数作用于链表中的每一项                  */ 
/*      plist指向一个已初始化的链表                 */ 
/*      pfun指向一个函数，该函数接受一个Item类型的参数，且无返回值   */
/* 后置条件:  pfun指向的函数作用于链表中的每一项一次            */
void Traverse(const List *plist, void(*pfun)(Item item));

#endif