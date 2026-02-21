/* array_list.h - 顺序表头文件 */
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "common.h"

/* 顺序表结构 */
typedef struct {
    ElemType data[MAX_SIZE];
    int length;
} SeqList;

/* 函数声明 */
Status InitList(SeqList *L);
bool ListEmpty(SeqList L);
int ListLength(SeqList L);
Status GetElem(SeqList L, int i, ElemType *e);
int LocateElem(SeqList L, ElemType e);
Status ListInsert(SeqList *L, int i, ElemType e);
Status ListDelete(SeqList *L, int i, ElemType *e);
void ListTraverse(SeqList L);
Status ClearList(SeqList *L);

#endif /* ARRAY_LIST_H */