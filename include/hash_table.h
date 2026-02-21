/* hash_table.h - 哈希表头文件 */
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "common.h"

#define HASH_SIZE 11

/* 哈希表结点 */
typedef struct HashNode {
    ElemType key;
    ElemType value;
    struct HashNode *next;
} HashNode;

/* 哈希表结构 */
typedef struct {
    HashNode *buckets[HASH_SIZE];
    int size;
} HashTable;

/* 函数声明 */
Status InitHashTable(HashTable *H);
Status HashInsert(HashTable *H, ElemType key, ElemType value);
Status HashSearch(HashTable H, ElemType key, ElemType *value);
Status HashDelete(HashTable *H, ElemType key);
void PrintHashTable(HashTable H);
Status DestroyHashTable(HashTable *H);

#endif /* HASH_TABLE_H */