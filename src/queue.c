/* queue.c - 队列实现 */
#include "../include/queue.h"

/* ================= 循环队列 ================= */
Status InitQueue(CirQueue *Q) {
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

int QueueLength(CirQueue Q) {
    return (Q.rear - Q.front + MAX_SIZE) % MAX_SIZE;
}

bool QueueEmpty(CirQueue Q) {
    return Q.front == Q.rear;
}

bool QueueFull(CirQueue Q) {
    return (Q.rear + 1) % MAX_SIZE == Q.front;
}

Status EnQueue(CirQueue *Q, ElemType e) {
    if (QueueFull(*Q)) return ERROR;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAX_SIZE;
    return OK;
}

Status DeQueue(CirQueue *Q, ElemType *e) {
    if (QueueEmpty(*Q)) return ERROR;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAX_SIZE;
    return OK;
}

Status GetHead(CirQueue Q, ElemType *e) {
    if (QueueEmpty(Q)) return ERROR;
    *e = Q.data[Q.front];
    return OK;
}

void PrintQueue(CirQueue Q) {
    printf("队列内容: ");
    int i = Q.front;
    while (i != Q.rear) {
        printf("%d ", Q.data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

/* ================= 链队列 ================= */
Status InitLinkQueue(LinkQueue *Q) {
    MALLOC(Q->front, sizeof(QNode));
    Q->front->next = NULL;
    Q->rear = Q->front;
    return OK;
}

bool LinkQueueEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}

Status LinkEnQueue(LinkQueue *Q, ElemType e) {
    QNode *node;
    MALLOC(node, sizeof(QNode));
    node->data = e;
    node->next = NULL;
    Q->rear->next = node;
    Q->rear = node;
    return OK;
}

Status LinkDeQueue(LinkQueue *Q, ElemType *e) {
    if (LinkQueueEmpty(*Q)) return ERROR;
    QNode *p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p) {
        Q->rear = Q->front;
    }
    free(p);
    return OK;
}

Status LinkGetHead(LinkQueue Q, ElemType *e) {
    if (LinkQueueEmpty(Q)) return ERROR;
    *e = Q.front->next->data;
    return OK;
}

int LinkQueueLength(LinkQueue Q) {
    int count = 0;
    QueuePtr p = Q.front->next;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void PrintLinkQueue(LinkQueue Q) {
    printf("链队列内容: ");
    QueuePtr p = Q.front->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

Status ClearLinkQueue(LinkQueue *Q) {
    QueuePtr p = Q->front->next;
    QueuePtr temp;
    while (p != NULL) {
        temp = p->next;
        free(p);
        p = temp;
    }
    Q->front->next = NULL;
    Q->rear = Q->front;
    return OK;
}

Status DestroyLinkQueue(LinkQueue *Q) {
    ClearLinkQueue(Q);
    free(Q->front);
    Q->front = NULL;
    Q->rear = NULL;
    return OK;
}