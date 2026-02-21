/* linked_list.h - 单链表头文件 */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "common.h"

/* 链表结点结构 */
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node, *LinkList;

/* 函数声明 */
Status InitList_LL(LinkList *L);
bool ListEmpty_LL(LinkList L);
int ListLength_LL(LinkList L);
Status GetElem_LL(LinkList L, int i, ElemType *e);
int LocateElem_LL(LinkList L, ElemType e);
Status ListInsert_LL(LinkList L, int i, ElemType e);
Status ListDelete_LL(LinkList L, int i, ElemType *e);
void ListTraverse_LL(LinkList L);
Status ClearList_LL(LinkList L);
Status DestroyList_LL(LinkList *L);
Status ReverseList_LL(LinkList L);

#endif /* LINKED_LIST_H */