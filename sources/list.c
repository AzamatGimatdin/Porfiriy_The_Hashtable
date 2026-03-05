#ifndef LIST_C
#define LIST_C

#include "common.h"
#include "list.h"

int list_create(list* l) {
    if (!l) return -1;

    l->head = NULL;
    l->tail = NULL;
    l->size = 0;

    return 0;
}

void list_free(list* l) {
    if (!l) return;

    node* n = l->head;
    while (True) {
        if (n->next == NULL) {
            break;
        }
        else {
            n = n->next;
            free(n->prev);
        }
    }
}

int list_push_back(list* l, int key, int value) {
    if (!l) return -1;

    node* new = malloc(sizeof(node));
    if (!new) return -1;
    new->value = value;
    new->key = key;
    new->next = NULL;
    if (l->size == 0) {
        new->prev = NULL;
        l->head = new;
        l->tail = new;
    }
    else {
        l->tail->next = new;
        new->prev = l->tail;
        l->tail = new;
    }
    l->size++;
}

int list_push_front(list* l, int key, int value) {
    if (!l) return -1;

    node* new = malloc(sizeof(node));
    if (!new) return -1;
    new->value = value;
    new->key = key;
    new->prev = NULL;
    if (l->size == 0) {
        new->next = NULL;
        l->head = new;
        l->tail = new;
    }
    else {
        l->head->prev = new;
        new->next = l->head;
        l->head = new;
    }
    l->size++;
}

int list_pop_back(list* l) {
    if (!l) return -1;

    if (l->size == 1) {
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
        l->size = 0;
    }
    else if (l->size > 1) {             
        l->tail = l->tail->prev;
        free(l->tail->next);
        l->tail->next = NULL;
        l->size--;
    }
}

int list_pop_front(list* l) {
    if (!l) return -1;

    if (l->size == 1) {
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
        l->size = 0;
    }
    else if (l->size > 1) {             
        l->head = l->head->next;
        free(l->head->prev);
        l->head->prev = NULL;
        l->size--;
    }
}

#endif // LIST_C