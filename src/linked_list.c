/* linked_list.c - 单链表实现 */
#include "../include/linked_list.h"

Status InitList_LL(LinkList *L) {
    MALLOC(*L, sizeof(Node));
    (*L)->next = NULL;
    return OK;
}

bool ListEmpty_LL(LinkList L) {
    return L->next == NULL;
}

int ListLength_LL(LinkList L) {
    int count = 0;
    Node *p = L->next;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

Status GetElem_LL(LinkList L, int i, ElemType *e) {
    int j = 1;
    Node *p = L->next;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i) return ERROR;
    *e = p->data;
    return OK;
}

int LocateElem_LL(LinkList L, ElemType e) {
    int i = 1;
    Node *p = L->next;
    while (p != NULL) {
        if (p->data == e) return i;
        p = p->next;
        i++;
    }
    return 0;
}

Status ListInsert_LL(LinkList L, int i, ElemType e) {
    int j = 1;
    Node *p = L;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i) return ERROR;
    Node *s;
    MALLOC(s, sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete_LL(LinkList L, int i, ElemType *e) {
    int j = 1;
    Node *p = L;
    while (p->next != NULL && j < i) {
        p = p->next;
        j++;
    }
    if (p->next == NULL || j > i) return ERROR;
    Node *q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return OK;
}

void ListTraverse_LL(LinkList L) {
    Node *p = L->next;
    printf("链表内容: ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

Status ClearList_LL(LinkList L) {
    Node *p = L->next;
    Node *q;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
    return OK;
}

Status DestroyList_LL(LinkList *L) {
    ClearList_LL(*L);
    free(*L);
    *L = NULL;
    return OK;
}

Status ReverseList_LL(LinkList L) {
    Node *prev = NULL;
    Node *curr = L->next;
    Node *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    L->next = prev;
    return OK;
}