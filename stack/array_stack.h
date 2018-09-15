/**
 * @file array_stack.h
 * @author Nikhil Milind
 *
 * A structure that contains a Array stack of pointers.
 * No safety checking occurs on any operations to optimize speed,
 * so it is up to the user to check for out-of-bounds exceptions.
 */

#include "../list/array_list.h"

#ifndef DATA_STRUCTURES_ARRAY_STACK
#define DATA_STRUCTURES_ARRAY_STACK

struct array_stack
{
    ArrayList *list;

    void (*push) (struct array_stack *stack, void *value);
    void * (*pop) (struct array_stack *stack);
    void * (*peek) (struct array_stack *stack);
    int (*size) (struct array_stack *stack);
};

typedef struct array_stack ArrayStack;

extern void ArrayStackConstruct(ArrayStack *stack);

extern void ArrayStackDestroy(ArrayStack *stack);

#endif
