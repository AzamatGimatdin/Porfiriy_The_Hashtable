#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "common.h"
#include "list.h"
#include "vector_void.h"

typedef struct hashtable {
    vector_void v;
    int size;
} hashtable;

int hashtable_create(hashtable* ht);
int hashtable_free(hashtable* ht);

int key_generate(int value);

int hashtable_push(hashtable* ht, int value);

#endif // HASHTABLE_H