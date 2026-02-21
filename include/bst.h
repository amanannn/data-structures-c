/* bst.h - 二叉搜索树头文件 */
#ifndef BST_H
#define BST_H

#include "common.h"

/* 二叉搜索树结点结构 */
typedef struct BSTNode {
    ElemType data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

/* 函数声明 */
BSTree SearchBST(BSTree T, ElemType key);
Status InsertBST(BSTree *T, ElemType key);
Status DeleteBST(BSTree *T, ElemType key);
void InOrderBST(BSTree T);
BSTNode* FindMin(BSTree T);
BSTNode* FindMax(BSTree T);

#endif /* BST_H */