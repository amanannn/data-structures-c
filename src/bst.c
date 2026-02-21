/* bst.c - 二叉搜索树实现 */
#include "../include/bst.h"

static Status DeleteNode(BSTree *p);

BSTree SearchBST(BSTree T, ElemType key) {
    if (T == NULL || T->data == key) return T;
    if (key < T->data) return SearchBST(T->lchild, key);
    else return SearchBST(T->rchild, key);
}

Status InsertBST(BSTree *T, ElemType key) {
    if (*T == NULL) {
        MALLOC(*T, sizeof(BSTNode));
        (*T)->data = key;
        (*T)->lchild = (*T)->rchild = NULL;
        return OK;
    }
    if (key == (*T)->data) return ERROR;
    else if (key < (*T)->data) return InsertBST(&(*T)->lchild, key);
    else return InsertBST(&(*T)->rchild, key);
}

Status DeleteBST(BSTree *T, ElemType key) {
    if (*T == NULL) return ERROR;
    if (key == (*T)->data) return DeleteNode(T);
    else if (key < (*T)->data) return DeleteBST(&(*T)->lchild, key);
    else return DeleteBST(&(*T)->rchild, key);
}

static Status DeleteNode(BSTree *p) {
    BSTree q, s;
    if ((*p)->lchild == NULL && (*p)->rchild == NULL) {
        free(*p);
        *p = NULL;
    } else if ((*p)->lchild == NULL) {
        q = *p;
        *p = (*p)->rchild;
        free(q);
    } else if ((*p)->rchild == NULL) {
        q = *p;
        *p = (*p)->lchild;
        free(q);
    } else {
        q = *p;
        s = (*p)->lchild;
        while (s->rchild != NULL) {
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data;
        if (q != *p) q->rchild = s->lchild;
        else q->lchild = s->lchild;
        free(s);
    }
    return OK;
}

void InOrderBST(BSTree T) {
    if (T == NULL) return;
    InOrderBST(T->lchild);
    printf("%d ", T->data);
    InOrderBST(T->rchild);
}

BSTNode* FindMin(BSTree T) {
    if (T == NULL) return NULL;
    while (T->lchild != NULL) T = T->lchild;
    return T;
}

BSTNode* FindMax(BSTree T) {
    if (T == NULL) return NULL;
    while (T->rchild != NULL) T = T->rchild;
    return T;
}