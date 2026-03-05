#ifndef VECTOR_C
#define VECTOR_C

#include "common.h"
#include "vector_void.h"

int vector_create(vector_void* v) {
  if (!v) return -1;

  void** data = (void**) calloc(100, sizeof(void*));
  if (!data) return -1;
  
  v->data = data;
  v->size = 100;
  v->occupied = 0;

  return 0;
}

void vector_free(vector_void* v) {
  if (!v) return;
  if (!v->data) return;

  free(v->data);
}

int vector_push_back(vector_void* v, void* value) {
  if (!v) return -1;

  if (v->occupied == v->size) {
    int status = vector_resize(v, v->size * 2);
    if (status != 0) return status;
  }

  v->data[v->occupied] = value;
  return 0;
}

int vector_resize(vector_void* v, int new_size) {
  if (!v) return -1;
  
  void** new_data = realloc(v->data, sizeof(void*) * new_size);
  if (!new_data) return -1;

  v->data = new_data;

  return 0;
}

#endif // VECTOR_C