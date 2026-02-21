/* common.h - 公共定义和工具函数 */
#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

/* 状态码定义 */
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

typedef int Status;
typedef int ElemType;

/* 内存分配宏 */
#define MALLOC(p, s) \
    if (!((p) = malloc(s))) { \
        printf("内存分配失败\n"); \
        exit(EXIT_FAILURE); \
    }

/* 交换两个元素 */
static inline void swap(ElemType *a, ElemType *b) {
    ElemType temp = *a;
    *a = *b;
    *b = temp;
}

/* 打印分隔线 */
static inline void print_separator() {
    printf("\n========================================\n\n");
}

#endif /* COMMON_H */