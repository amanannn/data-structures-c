/* queue.h - 队列头文件 */
#ifndef QUEUE_H
#define QUEUE_H

#include "common.h"

/* ================= 循环队列 ================= */
typedef struct {
    ElemType data[MAX_SIZE];
    int front;
    int rear;
} CirQueue;

Status InitQueue(CirQueue *Q);
int QueueLength(CirQueue Q);
bool QueueEmpty(CirQueue Q);
bool QueueFull(CirQueue Q);
Status EnQueue(CirQueue *Q, ElemType e);
Status DeQueue(CirQueue *Q, ElemType *e);
Status GetHead(CirQueue Q, ElemType *e);
void PrintQueue(CirQueue Q);

/* ================= 链队列 ================= */
typedef struct QNode {
    ElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

Status InitLinkQueue(LinkQueue *Q);
bool LinkQueueEmpty(LinkQueue Q);
Status LinkEnQueue(LinkQueue *Q, ElemType e);
Status LinkDeQueue(LinkQueue *Q, ElemType *e);
Status LinkGetHead(LinkQueue Q, ElemType *e);
int LinkQueueLength(LinkQueue Q);
void PrintLinkQueue(LinkQueue Q);
Status ClearLinkQueue(LinkQueue *Q);
Status DestroyLinkQueue(LinkQueue *Q);

#endif /* QUEUE_H */