/* stack.c - 栈实现 */
#include "../include/stack.h"

/* ================= 顺序栈 ================= */
Status InitStack(SqStack *S) {
    S->top = -1;
    return OK;
}

bool StackEmpty(SqStack S) {
    return S.top == -1;
}

Status GetTop(SqStack S, ElemType *e) {
    if (S.top == -1) return ERROR;
    *e = S.data[S.top];
    return OK;
}

Status Push(SqStack *S, ElemType e) {
    if (S->top >= MAX_SIZE - 1) return ERROR;
    S->data[++(S->top)] = e;
    return OK;
}

Status Pop(SqStack *S, ElemType *e) {
    if (S->top == -1) return ERROR;
    *e = S->data[(S->top)--];
    return OK;
}

int StackSize(SqStack S) {
    return S.top + 1;
}

void PrintStack(SqStack S) {
    printf("栈内容: ");
    for (int i = 0; i <= S.top; i++) {
        printf("%d ", S.data[i]);
    }
    printf("\n");
}

/* ================= 链栈 ================= */
Status InitLinkStack(LinkStack *S) {
    S->top = NULL;
    S->count = 0;
    return OK;
}

bool LinkStackEmpty(LinkStack S) {
    return S.count == 0;
}

Status LinkPush(LinkStack *S, ElemType e) {
    StackNode *node;
    MALLOC(node, sizeof(StackNode));
    node->data = e;
    node->next = S->top;
    S->top = node;
    S->count++;
    return OK;
}

Status LinkPop(LinkStack *S, ElemType *e) {
    if (S->count == 0) return ERROR;
    StackNode *p = S->top;
    *e = p->data;
    S->top = p->next;
    free(p);
    S->count--;
    return OK;
}

Status LinkGetTop(LinkStack S, ElemType *e) {
    if (S.count == 0) return ERROR;
    *e = S.top->data;
    return OK;
}

int LinkStackSize(LinkStack S) {
    return S.count;
}

void PrintLinkStack(LinkStack S) {
    printf("链栈内容: ");
    StackNode *p = S.top;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

Status ClearLinkStack(LinkStack *S) {
    while (S->top != NULL) {
        StackNode *p = S->top;
        S->top = p->next;
        free(p);
    }
    S->count = 0;
    return OK;
}

Status DestroyLinkStack(LinkStack *S) {
    ClearLinkStack(S);
    return OK;
}