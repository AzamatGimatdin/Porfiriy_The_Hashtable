#ifndef HASHTABLE_C
#define HASHTABLE_C

#include "hashtable.h"

int hashtable_create(hashtable* h) {
    if (!h) return -1;

    h->k = rand() % (int)1e7;
    h->b = rand() % (int)1e7;

    h->size = 0;

    int status = vector_create(&(h->data));
    return status;
}

void hashtable_free(hashtable* h) {
    if (!h) return -1;

    vector_free(&(h->data));
}

int hashtable_set(hashtable* h, int key, int value) {
    if (!h) return -1;

    int status;

    int hash = (h->k * key + h->b) % h->data.size;

    int isfound = 0;
    node* now = h->data.data[hash].head;

    while (now != NULL) {
        if (now->key == key) {
            isfound = 1;
            break;
        }

        now = now->next;
    }

    if (isfound) {
        now->value = value;
        return 0;
    } else {
        status = list_push_back(&(h->data.data[hash]), key, value);
        return status;
    }
}

int hashtable_delete(hashtable* h, int key);

int hashtable_search(hashtable* h, int key, int* return_value);

#endif  // HASHTABLE_C