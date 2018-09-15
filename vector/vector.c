#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

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
static void * get(Vector *vector, const unsigned int index)
{
    if (index >= vector->list->size) {
        fprintf(stderr, "Index out of bounds!");
        exit(EXIT_FAILURE);
    }

    return vector->list->get(vector->list, index);
}

static void * set(Vector *vector, const unsigned int index, const void *value)
{
    if (index >= vector->list->size) {
        fprintf(stderr, "Index out of bounds!");
        exit(EXIT_FAILURE);
    }

    //void *old = vector->list->get(index);
    //vector->list->set(vector->list, index, value);

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