/* hash_table.c - 哈希表实现 */
#include "../include/hash_table.h"

static int HashFunc(ElemType key) {
    return key % HASH_SIZE;
}

Status InitHashTable(HashTable *H) {
    H->size = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        H->buckets[i] = NULL;
    }
    return OK;
}

Status HashInsert(HashTable *H, ElemType key, ElemType value) {
    int index = HashFunc(key);
    HashNode *p = H->buckets[index];
    while (p != NULL) {
        if (p->key == key) {
            p->value = value;
            return OK;
        }
        p = p->next;
    }
    HashNode *node;
    MALLOC(node, sizeof(HashNode));
    node->key = key;
    node->value = value;
    node->next = H->buckets[index];
    H->buckets[index] = node;
    H->size++;
    return OK;
}

Status HashSearch(HashTable H, ElemType key, ElemType *value) {
    int index = HashFunc(key);
    HashNode *p = H.buckets[index];
    while (p != NULL) {
        if (p->key == key) {
            *value = p->value;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
}

Status HashDelete(HashTable *H, ElemType key) {
    int index = HashFunc(key);
    HashNode *p = H->buckets[index];
    HashNode *prev = NULL;
    while (p != NULL) {
        if (p->key == key) {
            if (prev == NULL) H->buckets[index] = p->next;
            else prev->next = p->next;
            free(p);
            H->size--;
            return OK;
        }
        prev = p;
        p = p->next;
    }
    return ERROR;
}

void PrintHashTable(HashTable H) {
    printf("哈希表内容:\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("[%d]: ", i);
        HashNode *p = H.buckets[i];
        while (p != NULL) {
            printf("(%d,%d) -> ", p->key, p->value);
            p = p->next;
        }
        printf("NULL\n");
    }
}

Status DestroyHashTable(HashTable *H) {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode *p = H->buckets[i];
        while (p != NULL) {
            HashNode *temp = p;
            p = p->next;
            free(temp);
        }
        H->buckets[i] = NULL;
    }
    H->size = 0;
    return OK;
}