/* binary_tree.c - 二叉树实现 */
#include "../include/binary_tree.h"

Status CreateBiTree(BiTree *T) {
    ElemType ch;
    printf("输入结点值(-1 表示空): ");
    scanf("%d", &ch);
    if (ch == -1) {
        *T = NULL;
    } else {
        MALLOC(*T, sizeof(BiTNode));
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
    return OK;
}

void PreOrderTraverse(BiTree T) {
    if (T == NULL) return;
    printf("%d ", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiTree T) {
    if (T == NULL) return;
    InOrderTraverse(T->lchild);
    printf("%d ", T->data);
    InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BiTree T) {
    if (T == NULL) return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%d ", T->data);
}

int TreeDepth(BiTree T) {
    if (T == NULL) return 0;
    int left = TreeDepth(T->lchild);
    int right = TreeDepth(T->rchild);
    return (left > right ? left : right) + 1;
}

int NodeCount(BiTree T) {
    if (T == NULL) return 0;
    return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

int LeafCount(BiTree T) {
    if (T == NULL) return 0;
    if (T->lchild == NULL && T->rchild == NULL) return 1;
    return LeafCount(T->lchild) + LeafCount(T->rchild);
}

void LevelOrderTraverse(BiTree T) {
    if (T == NULL) return;
    BiTree queue[100];
    int front = 0, rear = 0;
    queue[rear++] = T;
    while (front < rear) {
        BiTree p = queue[front++];
        printf("%d ", p->data);
        if (p->lchild) queue[rear++] = p->lchild;
        if (p->rchild) queue[rear++] = p->rchild;
    }
    printf("\n");
}

Status DestroyBiTree(BiTree *T) {
    if (*T == NULL) return OK;
    DestroyBiTree(&(*T)->lchild);
    DestroyBiTree(&(*T)->rchild);
    free(*T);
    *T = NULL;
    return OK;
}