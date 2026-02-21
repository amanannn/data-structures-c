/* heap.h - 堆头文件 */
#ifndef HEAP_H
#define HEAP_H

#include "common.h"

/* 堆结构 */
typedef struct {
    ElemType data[MAX_SIZE];
    int size;
} Heap;

/* 函数声明 */
Status InitHeap(Heap *H);
Status HeapInsert(Heap *H, ElemType e);
Status HeapExtractMax(Heap *H, ElemType *e);
Status HeapGetMax(Heap H, ElemType *e);
void PrintHeap(Heap H);
Status BuildHeap(Heap *H, ElemType arr[], int n);
Status HeapSort(ElemType arr[], int n);

#endif /* HEAP_H */