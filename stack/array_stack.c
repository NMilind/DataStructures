#include "array_stack.h"
#include <stdlib.h>
#include "../list/array_list.h"

/*
 * Instance Member Functions
 */

/**
 * Push a new pointer onto the stack
 * @param stack the stack to augment
 * @param value the pointer to push
 */
static void push (ArrayStack *stack, void *value)
{
    stack->list->addLast(stack->list, value);
}

/**
 * Pop a pointer off of the stack
 * @param stack the stack to augment
 * @return the pointer at the top of the stack
 */
static void * pop (ArrayStack *stack)
{
    return stack->list->removeLast(stack->list);
}

/**
 * Peek at the pointer at the top
 * @param stack the stack to query
 * @return the pointer at the top of the stack
 */
static void * peek (ArrayStack *stack)
{
    return stack->list->get(stack->list, stack->list->size - 1);
}

/**
 * Returns the size of the stack
 * @param stack the stack to query
 * @return the size of the stack
 */
static int size (ArrayStack *stack)
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
void ArrayStackConstruct(ArrayStack *stack)
{
    stack->list = (ArrayList *) malloc(sizeof(ArrayList));
    ArrayListConstruct(stack->list);

    stack->push = &push;
    stack->pop = &pop;
    stack->peek = &peek;
    stack->size = &size;
}

/**
 * Destroys an existing stack
 * @param stack the stack to be destroyed
 */
void ArrayStackDestroy(ArrayStack *stack)
{
    ArrayListDestroy(stack->list);
    free(stack->list);
}