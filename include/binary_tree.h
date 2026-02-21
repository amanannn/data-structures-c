/* binary_tree.h - 二叉树头文件 */
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "common.h"

/* 二叉树结点结构 */
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

/* 函数声明 */
Status CreateBiTree(BiTree *T);
void PreOrderTraverse(BiTree T);
void InOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);
void LevelOrderTraverse(BiTree T);
int TreeDepth(BiTree T);
int NodeCount(BiTree T);
int LeafCount(BiTree T);
Status DestroyBiTree(BiTree *T);

#endif /* BINARY_TREE_H */