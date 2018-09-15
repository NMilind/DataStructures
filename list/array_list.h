/**
 * @file array_list.h
 * @author Nikhil Milind
 *
 * A structure that contains an Array List of pointers.
 * The pointers can be of any kind. The list will automatically
 * resize when necessary, doubling in capacity as required.
 * No safety checking occurs on any operations to optimize speed,
 * so it is up to the user to check for out-of-bounds exceptions.
 */

#include <stdlib.h>

#ifndef DATA_STRUCTURES_ARRAY_LIST
#define DATA_STRUCTURES_ARRAY_LIST

struct array_list
{
    size_t size;
    size_t capacity;
    void **data;

    void (*set) (struct array_list *list, const size_t index, void *value);
    void * (*get) (struct array_list *list, const size_t index);

    void (*add) (struct array_list *list, const size_t index, void *value);
    void (*addFirst) (struct array_list *list, void *value);
    void (*addLast) (struct array_list *list, void *value);

    void * (*remove) (struct array_list *list, const size_t index);
    void * (*removeFirst) (struct array_list *list);
    void * (*removeLast) (struct array_list *list);
};

typedef struct array_list ArrayList;

extern void ArrayListConstruct(ArrayList *list);

extern void ArrayListDestroy(ArrayList *list);

#endif