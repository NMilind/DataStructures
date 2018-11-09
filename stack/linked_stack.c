#include "linked_stack.h"
#include <stdlib.h>
#include "../list/doubly_linked_list.h"

/*
 * Instance Member Functions
 */

/**
 * Push a new pointer onto the stack
 * @param stack the stack to augment
 * @param value the pointer to push
 */
static void push (LinkedStack *stack, void *value)
{
    stack->list->addFirst(stack->list, value);
}

/**
 * Pop a pointer off of the stack
 * @param stack the stack to augment
 * @return the pointer at the top of the stack
 */
static void * pop (LinkedStack *stack)
{
    return stack->list->removeFirst(stack->list);
}

/**
 * Peek at the pointer at the top
 * @param stack the stack to query
 * @return the pointer at the top of the stack
 */
static void * peek (LinkedStack *stack)
{
    return stack->list->get(stack->list, 0);
}

/**
 * Returns the size of the stack
 * @param stack the stack to query
 * @return the size of the stack
 */
static size_t size (LinkedStack *stack)
{
    return stack->list->size;
}

/*
 * Construction / Destruction
 */

/**
 * Constructs a new Array Stack instance.
 * @param stack the stack to be constructed
 */
LinkedStack *LinkedStackConstruct()
{
    LinkedStack *stack = (LinkedStack *)malloc(sizeof(LinkedStack));

    stack->list = (DoublyLinkedList *) malloc(sizeof(DoublyLinkedList));
    DoublyLinkedListConstruct(stack->list);

    stack->push = &push;
    stack->pop = &pop;
    stack->peek = &peek;
    stack->size = &size;

    return stack;
}

/**
 * Destroys an existing stack
 * @param stack the stack to be destroyed
 */
void LinkedStackDestroy(LinkedStack *stack)
{
    DoublyLinkedListDestroy(stack->list);
    free(stack->list);
    free(stack);
}