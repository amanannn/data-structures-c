/* stack.h - 栈头文件 */
#ifndef STACK_H
#define STACK_H

#include "common.h"

/* ================= 顺序栈 ================= */
typedef struct {
    ElemType data[MAX_SIZE];
    int top;
} SqStack;

Status InitStack(SqStack *S);
bool StackEmpty(SqStack S);
Status GetTop(SqStack S, ElemType *e);
Status Push(SqStack *S, ElemType e);
Status Pop(SqStack *S, ElemType *e);
int StackSize(SqStack S);
void PrintStack(SqStack S);

/* ================= 链栈 ================= */
typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct {
    LinkStackPtr top;
    int count;
} LinkStack;

Status InitLinkStack(LinkStack *S);
bool LinkStackEmpty(LinkStack S);
Status LinkPush(LinkStack *S, ElemType e);
Status LinkPop(LinkStack *S, ElemType *e);
Status LinkGetTop(LinkStack S, ElemType *e);
int LinkStackSize(LinkStack S);
void PrintLinkStack(LinkStack S);
Status ClearLinkStack(LinkStack *S);
Status DestroyLinkStack(LinkStack *S);

#endif /* STACK_H */