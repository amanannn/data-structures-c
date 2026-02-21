/* main.c - 测试主程序 */
#include <stdio.h>
#include "include/common.h"
#include "include/array_list.h"
#include "include/linked_list.h"
#include "include/stack.h"
#include "include/queue.h"
#include "include/binary_tree.h"
#include "include/bst.h"
#include "include/heap.h"
#include "include/hash_table.h"
#include "include/graph.h"
#include "include/sort.h"

/* 全局变量（图遍历需要） */
bool visited[MAX_VERTICES];

/* ================= 测试函数声明 ================= */
void test_seq_list();
void test_linked_list();
void test_stack();
void test_link_stack();
void test_queue();
void test_link_queue();
void test_binary_tree();
void test_bst();
void test_heap();
void test_hash_table();
void test_graph();
void test_sort();

/* ================= 主函数 ================= */
int main() {
    printf("╔════════════════════════════════════╗\n");
    printf("║     C 语言数据结构学习程序          ║\n");
    printf("╚════════════════════════════════════╝\n\n");
    
    int choice;
    
    while (1) {
        printf("\n┌────────────────────────────────────┐\n");
        printf("│ 请选择要测试的数据结构:            │\n");
        printf("├────────────────────────────────────┤\n");
        printf("│ 1. 顺序表                          │\n");
        printf("│ 2. 链表                            │\n");
        printf("│ 3. 栈（顺序栈）                    │\n");
        printf("│ 4. 栈（链栈）                      │\n");
        printf("│ 5. 队列（循环队列）                │\n");
        printf("│ 6. 队列（链队列）                  │\n");
        printf("│ 7. 二叉树                          │\n");
        printf("│ 8. 二叉搜索树                      │\n");
        printf("│ 9. 堆                              │\n");
        printf("│ 10. 哈希表                         │\n");
        printf("│ 11. 图                             │\n");
        printf("│ 12. 排序算法                       │\n");
        printf("│ 0. 退出                            │\n");
        printf("└────────────────────────────────────┘\n");
        printf("请输入选项: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: test_seq_list(); break;
            case 2: test_linked_list(); break;
            case 3: test_stack(); break;
            case 4: test_link_stack(); break;
            case 5: test_queue(); break;
            case 6: test_link_queue(); break;
            case 7: test_binary_tree(); break;
            case 8: test_bst(); break;
            case 9: test_heap(); break;
            case 10: test_hash_table(); break;
            case 11: test_graph(); break;
            case 12: test_sort(); break;
            case 0: 
                printf("感谢使用，再见！\n");
                return 0;
            default:
                printf("无效选项！\n");
        }
    }
    
    return 0;
}

/* ================= 测试函数实现 ================= */

void test_seq_list() {
    print_separator();
    printf("【顺序表测试】\n\n");
    SeqList L;
    InitList(&L);
    printf("插入元素: 10, 20, 30, 40, 50\n");
    for (int i = 1; i <= 5; i++) ListInsert(&L, i, i * 10);
    ListTraverse(L);
    printf("查找元素 30 的位置：%d\n", LocateElem(L, 30));
    ElemType e;
    ListDelete(&L, 3, &e);
    printf("删除第 3 个元素：%d\n", e);
    ListTraverse(L);
    printf("顺序表长度：%d\n", ListLength(L));
}

void test_linked_list() {
    print_separator();
    printf("【链表测试】\n\n");
    LinkList L;
    InitList_LL(&L);
    printf("插入元素：10, 20, 30\n");
    for (int i = 1; i <= 3; i++) ListInsert_LL(L, 1, i * 10);
    ListTraverse_LL(L);
    printf("链表逆置后:\n");
    ReverseList_LL(L);
    ListTraverse_LL(L);
    DestroyList_LL(&L);
}

void test_stack() {
    print_separator();
    printf("【顺序栈测试】\n\n");
    SqStack S;
    InitStack(&S);
    printf("入栈: 10, 20, 30, 40, 50\n");
    for (int i = 1; i <= 5; i++) Push(&S, i * 10);
    PrintStack(S);
    ElemType e;
    Pop(&S, &e);
    printf("出栈元素：%d\n", e);
    PrintStack(S);
}

void test_link_stack() {
    print_separator();
    printf("【链栈测试】\n\n");
    LinkStack S;
    InitLinkStack(&S);
    printf("入栈: 10, 20, 30, 40, 50\n");
    for (int i = 1; i <= 5; i++) LinkPush(&S, i * 10);
    PrintLinkStack(S);
    printf("栈大小：%d\n", LinkStackSize(S));
    ElemType e;
    LinkPop(&S, &e);
    printf("出栈元素：%d\n", e);
    PrintLinkStack(S);
    DestroyLinkStack(&S);
}

void test_queue() {
    print_separator();
    printf("【循环队列测试】\n\n");
    CirQueue Q;
    InitQueue(&Q);
    printf("入队: 10, 20, 30, 40, 50\n");
    for (int i = 1; i <= 5; i++) EnQueue(&Q, i * 10);
    PrintQueue(Q);
    ElemType e;
    DeQueue(&Q, &e);
    printf("出队元素：%d\n", e);
    PrintQueue(Q);
}

void test_link_queue() {
    print_separator();
    printf("【链队列测试】\n\n");
    LinkQueue Q;
    InitLinkQueue(&Q);
    printf("入队: 10, 20, 30, 40, 50\n");
    for (int i = 1; i <= 5; i++) LinkEnQueue(&Q, i * 10);
    PrintLinkQueue(Q);
    printf("队列长度：%d\n", LinkQueueLength(Q));
    ElemType e;
    LinkDeQueue(&Q, &e);
    printf("出队元素：%d\n", e);
    PrintLinkQueue(Q);
    DestroyLinkQueue(&Q);
}

void test_binary_tree() {
    print_separator();
    printf("【二叉树测试】\n\n");
    BiTree T;
    printf("请按先序输入结点（-1 表示空）:\n");
    printf("例如: 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1\n");
    CreateBiTree(&T);
    printf("\n先序遍历: "); PreOrderTraverse(T); printf("\n");
    printf("中序遍历: "); InOrderTraverse(T); printf("\n");
    printf("后序遍历: "); PostOrderTraverse(T); printf("\n");
    printf("层序遍历: "); LevelOrderTraverse(T);
    printf("树的深度：%d\n", TreeDepth(T));
    printf("结点总数：%d\n", NodeCount(T));
    printf("叶子结点数：%d\n", LeafCount(T));
    DestroyBiTree(&T);
}

void test_bst() {
    print_separator();
    printf("【二叉搜索树测试】\n\n");
    BSTree T = NULL;
    printf("插入: 50, 30, 70, 20, 40, 60, 80\n");
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) InsertBST(&T, arr[i]);
    printf("中序遍历（有序）: "); InOrderBST(T); printf("\n");
    printf("查找 40: %s\n", SearchBST(T, 40) ? "找到" : "未找到");
    DeleteBST(&T, 30);
    printf("删除 30 后: "); InOrderBST(T); printf("\n");
}

void test_heap() {
    print_separator();
    printf("【堆测试】\n\n");
    Heap H;
    InitHeap(&H);
    printf("插入: 50, 30, 70, 20, 40\n");
    HeapInsert(&H, 50);
    HeapInsert(&H, 30);
    HeapInsert(&H, 70);
    HeapInsert(&H, 20);
    HeapInsert(&H, 40);
    PrintHeap(H);
    ElemType max;
    HeapExtractMax(&H, &max);
    printf("提取最大值：%d\n", max);
    PrintHeap(H);
}

void test_hash_table() {
    print_separator();
    printf("【哈希表测试】\n\n");
    HashTable H;
    InitHashTable(&H);
    printf("插入: (10,100), (21,200), (32,300), (43,400)\n");
    HashInsert(&H, 10, 100);
    HashInsert(&H, 21, 200);
    HashInsert(&H, 32, 300);
    HashInsert(&H, 43, 400);
    PrintHashTable(H);
    ElemType value;
    if (HashSearch(H, 21, &value) == OK) {
        printf("查找 key=21, value=%d\n", value);
    }
    DestroyHashTable(&H);
}

void test_graph() {
    print_separator();
    printf("【图测试】\n\n");
    MGraph G;
    InitMGraph(&G, 5);
    AddEdge(&G, 0, 1, 10);
    AddEdge(&G, 0, 4, 5);
    AddEdge(&G, 1, 2, 15);
    AddEdge(&G, 1, 4, 2);
    AddEdge(&G, 2, 3, 20);
    AddEdge(&G, 3, 4, 10);
    PrintMGraph(G);
    DFSTraverse_MGraph(G);
    BFS_MGraph(G);
    int dist[5];
    Dijkstra(G, 0, dist);
    printf("\n从顶点 0 到其他顶点的最短距离:\n");
    for (int i = 0; i < 5; i++) printf("到顶点%d: %d\n", i, dist[i]);
}

void test_sort() {
    print_separator();
    printf("【排序算法测试】\n\n");
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("原数组: "); PrintArray(arr, n);
    printf("冒泡排序: "); int arr1[] = {64, 34, 25, 12, 22, 11, 90}; BubbleSort(arr1, n); PrintArray(arr1, n);
    printf("快速排序: "); int arr2[] = {64, 34, 25, 12, 22, 11, 90}; QuickSort(arr2, 0, n - 1); PrintArray(arr2, n);
    printf("归并排序: "); int arr3[] = {64, 34, 25, 12, 22, 11, 90}; MergeSort(arr3, 0, n - 1); PrintArray(arr3, n);
    printf("堆排序: "); int arr4[] = {64, 34, 25, 12, 22, 11, 90}; HeapSortArr(arr4, n); PrintArray(arr4, n);
    int idx = BinarySearch(arr4, n, 25);
    printf("二分查找 25 的位置：%d\n", idx);
}