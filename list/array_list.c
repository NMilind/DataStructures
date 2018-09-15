#include "array_list.h"
#include <stdlib.h>

/*
 * Internal Functions
 */

/**
 * Increases the capacity of the underlying array by
 * doubling the amount of entries present.
 * @param list the list to be checked for growth
 * @param potential the potential new size for the list
 */
static void grow(ArrayList *list, const size_t potential)
{
    if (list->capacity == potential) {
        void **temp = calloc(list->capacity * 2, sizeof(void *));
        list->capacity *= 2;
        for (size_t i = 0; i < list->size; i++) {
            temp[i] = list->data[i];
        }
        free(list->data);
        list->data = temp;
    }
}

/*
 * Instance Member Functions
 */

/**
 * Sets the value of an element at a given index
 * @param list the list to be augmented
 * @param index the index at which to set a value
 * @param value the pointer to be stored
 */
static void set(ArrayList *list, const size_t index, void *value)
{
    list->data[index] = value;
}

/**
 * Returns the pointer stored at the index
 * @param list the list to be queried
 * @param index the index at which to retrieve the pointer
 * @return the pointer at the specified index
 */
static void * get(ArrayList *list, const size_t index)
{
    return list->data[index];
}

/**
 * Adds a pointer at the specified index.
 * @param list the list to be augmented
 * @param index the index at which to add the pointer
 * @param value the pointer to be added
 */
static void add(ArrayList *list, const size_t index, void *value)
{
    grow(list, list->size + 1);

    for (size_t i = list->size; i > index; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[index] = value;
    list->size++;
}

/**
 * Adds a pointer to the front of the list.
 * @param list the list to be augmented
 * @param value the pointer to add to the front
 */
static void addFirst(ArrayList *list, void *value)
{
    list->add(list, 0, value);
}

/**
 * Adds a pointer to the end of the list.
 * @param list the list to be augmented
 * @param value the pointer to add to the end of the list
 */
static void addLast(ArrayList *list, void *value)
{
    list->add(list, list->size, value);
}

/**
 * Removes and returns a pointer from the list.
 * @param list the list to be augmented
 * @param index the index at which to remove the pointer
 * @return the pointer that is removed
 */
static void * remove(ArrayList *list, const size_t index)
{
    void *reference = list->data[index];
    for (size_t i = index; i < list->size; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
    return reference;
}

/**
 * Removes the first pointer and returns it.
 * @param list the list to be augmented
 * @return the first pointer in the list
 */
static void * removeFirst(ArrayList *list)
{
    return list->remove(list, 0);
}

/**
 * Removes the last pointer and returns it.
 * @param list the list to be augmented
 * @return the last pointer in the list
 */
static void * removeLast(ArrayList *list)
{
    return list->remove(list, list->size - 1);
}

/*
 * Construction / Destruction
 */

/**
 * Constructs a new Array List structure with an
 * initial capacity of 10 elements.
 * @param list a pointer to a list structure instance
 */
void ArrayListConstruct(ArrayList *list)
{
    list->capacity = 10;
    list->size = 0;

    list->set = &set;
    list->get = &get;

    list->add = &add;
    list->addFirst = &addFirst;
    list->addLast = &addLast;

    list->remove = &remove;
    list->removeFirst = &removeFirst;
    list->removeLast = &removeLast;

    list->data = calloc(list->capacity, sizeof(void *));
}

/**
 * Destroys a given Array List instance
 * @param list a pointer to a list structure instance
 */
void ArrayListDestroy(ArrayList *list)
{
    free(list->data);
}