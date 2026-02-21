/* sort.h - 排序算法头文件 */
#ifndef SORT_H
#define SORT_H

#include "common.h"

/* 函数声明 */
void BubbleSort(ElemType arr[], int n);
void SelectionSort(ElemType arr[], int n);
void InsertionSort(ElemType arr[], int n);
void QuickSort(ElemType arr[], int low, int high);
void MergeSort(ElemType arr[], int left, int right);
void HeapSortArr(ElemType arr[], int n);
int BinarySearch(ElemType arr[], int n, ElemType target);
void PrintArray(ElemType arr[], int n);

#endif /* SORT_H */