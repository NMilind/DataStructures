/**
 * @file vector.h
 * @author Nikhil Milind
 *
 * A delegation for the Doubly Linked List implemented
 * beforehand. However, this structure has a strong
 * check for invalid inputs.
 */

#include <stdlib.h>
#include "../list/array_list.h"

#ifndef DATA_STRUCTURES_VECTOR
#define DATA_STRUCTURES_VECTOR

struct vector
{
    ArrayList *list;

    void * (*get) (struct vector *vector, const size_t index);
    void * (*set) (struct vector *vector, const size_t index, void *value);

    void * (*first) (struct vector *vector);
    void * (*last) (struct vector *vector);

    void (*add) (struct vector *vector, const size_t index, void *value);
    void (*addFirst) (struct vector *vector, void *value);
    void (*addLast) (struct vector *vector, void *value);

    void * (*rem) (struct vector *vector, const size_t index);
    void * (*remFirst) (struct vector *vector);
    void * (*remLast) (struct vector *vector);

    size_t (*size) (struct vector *vector);
};

typedef struct vector Vector;

extern void VectorConstruct(Vector *vector);

extern void VectorDestroy(Vector *vector);

#endif
