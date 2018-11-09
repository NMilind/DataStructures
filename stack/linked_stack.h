/**
 * @file linked_stack.h
 * @author Nikhil Milind
 *
 * A structure that contains a Linked stack of pointers.
 * No safety checking occurs on any operations to optimize speed,
 * so it is up to the user to check for out-of-bounds exceptions.
 */

#include <stdlib.h>
#include "../list/doubly_linked_list.h"

#ifndef DATA_STRUCTURES_LINKED_STACK
#define DATA_STRUCTURES_LINKED_STACK

struct linked_stack
{
    DoublyLinkedList *list;

    void (*push) (struct linked_stack *stack, void *value);
    void * (*pop) (struct linked_stack *stack);
    void * (*peek) (struct linked_stack *stack);
    size_t (*size) (struct linked_stack *stack);
};

typedef struct linked_stack LinkedStack;

extern LinkedStack *LinkedStackConstruct();

extern void LinkedStackDestroy(LinkedStack *stack);

#endif