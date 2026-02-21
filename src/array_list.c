/* array_list.c - 顺序表实现 */
#include "../include/array_list.h"

Status InitList(SeqList *L) {
    L->length = 0;
    return OK;
}

bool ListEmpty(SeqList L) {
    return L.length == 0;
}

int ListLength(SeqList L) {
    return L.length;
}

Status GetElem(SeqList L, int i, ElemType *e) {
    if (i < 1 || i > L.length) return ERROR;
    *e = L.data[i - 1];
    return OK;
}

int LocateElem(SeqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) return i + 1;
    }
    return 0;
}

Status ListInsert(SeqList *L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) return ERROR;
    if (L->length >= MAX_SIZE) return ERROR;
    for (int k = L->length - 1; k >= i - 1; k--) {
        L->data[k + 1] = L->data[k];
    }
    L->data[i - 1] = e;
    L->length++;
    return OK;
}

Status ListDelete(SeqList *L, int i, ElemType *e) {
    if (i < 1 || i > L->length) return ERROR;
    *e = L->data[i - 1];
    for (int k = i; k < L->length; k++) {
        L->data[k - 1] = L->data[k];
    }
    L->length--;
    return OK;
}

void ListTraverse(SeqList L) {
    printf("顺序表内容: ");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

Status ClearList(SeqList *L) {
    L->length = 0;
    return OK;
}