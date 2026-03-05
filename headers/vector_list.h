#ifndef VECTOR_H
#define VECTOR_H

#include "common.h"

typedef struct vector_void {
  void** data;
  ull size;
  ull occupied;
} vector_void;

int vector_create(vector_void* v);
void vector_free(vector_void* v);

int vector_push_back(vector_void* v, void* value);

int vector_resize(vector_void* v, int new_size);

#endif // VECTOR_H