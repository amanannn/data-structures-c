/* heap.c - 堆实现 */
#include "../include/heap.h"

Status InitHeap(Heap *H) {
    H->size = 0;
    return OK;
}

static int Parent(int i) { return (i - 1) / 2; }
static int LeftChild(int i) { return 2 * i + 1; }
static int RightChild(int i) { return 2 * i + 2; }

static void Swim(Heap *H, int i) {
    while (i > 0 && H->data[Parent(i)] < H->data[i]) {
        swap(&H->data[Parent(i)], &H->data[i]);
        i = Parent(i);
    }
}

static void Sink(Heap *H, int i) {
    int largest = i;
    int left = LeftChild(i);
    int right = RightChild(i);
    if (left < H->size && H->data[left] > H->data[largest]) largest = left;
    if (right < H->size && H->data[right] > H->data[largest]) largest = right;
    if (largest != i) {
        swap(&H->data[i], &H->data[largest]);
        Sink(H, largest);
    }
}

Status HeapInsert(Heap *H, ElemType e) {
    if (H->size >= MAX_SIZE) return ERROR;
    H->data[H->size] = e;
    Swim(H, H->size);
    H->size++;
    return OK;
}

Status HeapExtractMax(Heap *H, ElemType *e) {
    if (H->size == 0) return ERROR;
    *e = H->data[0];
    H->data[0] = H->data[H->size - 1];
    H->size--;
    Sink(H, 0);
    return OK;
}

Status HeapGetMax(Heap H, ElemType *e) {
    if (H.size == 0) return ERROR;
    *e = H.data[0];
    return OK;
}

void PrintHeap(Heap H) {
    printf("堆内容: ");
    for (int i = 0; i < H.size; i++) {
        printf("%d ", H.data[i]);
    }
    printf("\n");
}

Status BuildHeap(Heap *H, ElemType arr[], int n) {
    H->size = n;
    for (int i = 0; i < n; i++) H->data[i] = arr[i];
    for (int i = Parent(n - 1); i >= 0; i--) Sink(H, i);
    return OK;
}

Status HeapSort(ElemType arr[], int n) {
    Heap H;
    BuildHeap(&H, arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(&H.data[0], &H.data[i]);
        H.size--;
        Sink(&H, 0);
    }
    for (int i = 0; i < n; i++) arr[i] = H.data[i];
    return OK;
}