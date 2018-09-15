#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/*
 * Instance Member Functions
 */

/**
 * Returns the pointer at the specified index. Will exit
 * the program if the index is out of bounds.
 * @param vector the vector to query
 * @param index the index of the pointer
 * @return the pointer at the specified index
 */
static void * get(Vector *vector, const size_t index)
{
    if (index >= vector->list->size) {
        fprintf(stderr, "Index out of bounds");
        exit(EXIT_FAILURE);
    }

    return vector->list->get(vector->list, index);
}

/**
 * Sets the pointer at a specified index in the vector. Will
 * exit if the index is out of bounds.
 * @param vector the vector in which to set the pointer
 * @param index the index at which to set the value
 * @param value the pointer to set
 * @return the old pointer at the location
 */
static void * set(Vector *vector, const size_t index, void *value)
{
    if (index >= vector->list->size) {
        fprintf(stderr, "Index out of bounds");
        exit(EXIT_FAILURE);
    }

    void *old = vector->list->get(vector->list, index);
    vector->list->set(vector->list, index, value);
    return old;
}

/**
 * Returns the first pointer in the vector. Will exit from
 * the program if the list is empty.
 * @param vector the vector to query
 * @return the first pointer in the vector
 */
static void * first(Vector *vector)
{
    if (vector->list->size == 0) {
        fprintf(stderr, "Cannot access first element of an empty vector");
        exit(EXIT_FAILURE);
    }

    return vector->list->get(vector->list, 0);
}

/**
 * Returns the last pointer in the vector. Will exit from
 * the program is the list is empty.
 * @param vector the vector to query
 * @return the last pointer in the vector
 */
static void * last(Vector *vector)
{
    if (vector->list->size == 0) {
        fprintf(stderr, "Cannot access last element of an empty vector");
        exit(EXIT_FAILURE);
    }

    return vector->list->get(vector->list, vector->list->size - 1);
}

/**
 * Adds a pointer at the specified index. Will exit from
 * the program if the index is larger than the size of the
 * vector or if the vector is at maximum capacity (SIZE_T_MAX).
 * @param vector the vector to add a pointer to
 * @param index the index at which to add the pointer
 * @param value the pointer to add
 */
static void add(Vector *vector, const size_t index, void *value)
{
    if (index > vector->list->size) {
        fprintf(stderr, "Index out of bounds");
        exit(EXIT_FAILURE);
    }

    if (vector->list->size == SIZE_T_MAX) {
        fprintf(stderr, "Maximum capacity of vector reached");
        exit(EXIT_FAILURE);
    }

    vector->list->add(vector->list, index, value);
}

/**
 * Adds a pointer to the front of the vector. Will exit from
 * the program if the vector is at maximum capacity (SIZE_T_MAX);
 * @param vector the vector to add a pointer to
 * @param value the pointer to add
 */
static void addFirst(Vector *vector, void *value)
{
    vector->add(vector, 0, value);
}

/**
 * Adds a pointer to the end of the vector. Will exit from
 * the program if the vector is at maximum capacity (SIZE_T_MAX);
 * @param vector the vector to add a pointer to
 * @param value the pointer to add
 */
static void addLast(Vector *vector, void *value)
{
    vector->add(vector, vector->list->size, value);
}

/**
 * Removes a pointer from the vector and returns it. Will exit
 * from the program if the index is out of bounds.
 * @param vector the vector to augment
 * @param index the index at which to remove the pointer
 * @return the pointer that is removed
 */
static void * rem(Vector *vector, const size_t index)
{
    if (index >= vector->list->size) {
        fprintf(stderr, "Index out of bounds");
        exit(EXIT_FAILURE);
    }

    return vector->list->remove(vector->list, index);
}

/**
 * Removes a pointer from the front of the vector and returns it.
 * Will exit from the program if the vector is empty.
 * @param vector the vector to augment
 * @returs the pointer at the front of the vector
 */
static void * remFirst(Vector *vector)
{
    return vector->rem(vector, 0);
}

/**
 * Removes a pointer from the end of the vector and returns it.
 * Will exit from the program if the vector is empty.
 * @param vector the vector to augment
 * @returs the pointer at the front of the vector
 */
static void * remLast(Vector *vector)
{
    return vector->rem(vector, vector->list->size - 1);
}

/**
 * Returns the current size of the vector.
 * @param vector the vector to query
 * @return the size of the vector
 */
static size_t size(Vector *vector)
{
    return vector->list->size;
}

/*
 * Constructors / Destructors
 */

/**
 * Construct a new vector
 * @param vector the vector to construct
 */
void VectorConstruct(Vector *vector)
{
    vector->list = (ArrayList *) malloc(sizeof(ArrayList));
    ArrayListConstruct(vector->list);

    vector->get = &get;
    vector->set = &set;

    vector->first = &first;
    vector->last = &last;

    vector->add = &add;
    vector->addFirst = &addFirst;
    vector->addLast = &addLast;

    vector->rem = &rem;
    vector->remFirst = &remFirst;
    vector->remLast = &remLast;
}

/**
 * Destroy an instance of a vector
 * @param vector the vector to destroy
 */
void VectorDestroy(Vector *vector)
{
    ArrayListDestroy(vector->list);
    free(vector->list);
}