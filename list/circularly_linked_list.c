#include "circularly_linked_list.h"
#include <stdlib.h>

/*
 * Instance Member Functions
 */

/**
 * Sets the value of the pointer at a given index.
 * @param list the list to augment
 * @param index the index at which to set the value
 * @param value the new pointer value
 */
static void set(CircularlyLinkedList *list, const size_t index, void *value)
{
    size_t iterations = (index + 1) % list->size;

    CircularlyLinkedNode *current = list->tail;
    for (size_t i = 0; i < iterations; i++) {
        current = current->next;
    }
    current->data = value;
}

/**
 * Returns the value of the pointer at a given index
 * @param list the list to query
 * @param index the index to query
 * @return the pointer at the given index
 */
static void * get(CircularlyLinkedList *list, const size_t index)
{
    size_t iterations = (index + 1) % list->size;

    CircularlyLinkedNode *current = list->tail;
    for (size_t i = 0; i < iterations; i++) {
        current = current->next;
    }
    return current->data;
}

/**
 * Add a pointer at the specified index.
 * @param list the list to be augmented
 * @param index the index at which to add a pointer
 * @param value the pointer to add
 */
static void add(CircularlyLinkedList *list, const size_t index, void *value)
{
    // Handle first insertion into list
    if (list->size == 0) {
        CircularlyLinkedNode *insert = (CircularlyLinkedNode *) malloc(sizeof(CircularlyLinkedNode));
        insert->data = value;
        insert->next = insert;
        list->tail = insert;
        list->size++;
        return;
    }

    size_t iterations = index % list->size;

    CircularlyLinkedNode *current = list->tail;
    for (size_t i = 0; i < iterations; i++) {
        current = current->next;
    }

    CircularlyLinkedNode *insert = (CircularlyLinkedNode *) malloc(sizeof(CircularlyLinkedNode));
    insert->data = value;
    insert->next = current->next;
    current->next = insert;

    // Update tail pointer if necessary
    if (index == list->size) {
        list->tail = insert;
    }

    list->size++;
}

/**
 * Add a pointer at the beginning of the list.
 * @param list the list to augment
 * @param value the value to add
 */
static void addFirst(CircularlyLinkedList *list, void *value)
{
    list->add(list, 0, value);
}

/**
 * Add a pointer to the end of the list.
 * @param list the list to augment
 * @param value the value to add
 */
static void addLast(CircularlyLinkedList *list, void *value)
{
    list->add(list, list->size, value);
}

/**
 * Remove and return the pointer at the specified index.
 * @param list the list to augment
 * @param index the index to retrieve the pointer from
 * @return the pointer at the index specified
 */
static void * remove(CircularlyLinkedList *list, const size_t index)
{
    // Handle case of emptying list
    if (list->size == 1) {
        void *data = list->tail->data;
        free(list->tail);
        list->tail = NULL;
        list->size--;
        return data;
    }

    size_t iterations = index % list->size;

    CircularlyLinkedNode *current = list->tail;
    for (size_t i = 0; i < iterations; i++) {
        current = current->next;
    }

    CircularlyLinkedNode *insert = current->next;
    current->next = current->next->next;
    void *data = insert->data;
    free(insert);

    // Update tail pointer if necessary
    if (index == list->size - 1) {
        list->tail = current;
    }

    list->size--;

    return data;
}

/**
 * Remove the first pointer in the list and return it
 * @param list the list to augment
 * @return the pointer that is removed
 */
static void * removeFirst(CircularlyLinkedList *list)
{
    return list->remove(list, 0);
}

/**
 * Remove the last pointer in the list and return it
 * @param list the list to augment
 * @return the pointer that is removed
 */
static void * removeLast(CircularlyLinkedList *list)
{
    return list->remove(list, list->size - 1);
}

/*
 * Construction / Destruction
 */

/**
 * Constructs a new Circularly Linked List instance
 * with no sentinel nodes.
 * @param list the list to be constructed
 */
void CircularlyLinkedListConstruct(CircularlyLinkedList *list)
{
    list->size = 0;

    list->set = &set;
    list->get = &get;

    list->add = &add;
    list->addFirst = &addFirst;
    list->addLast = &addLast;

    list->remove = &remove;
    list->removeFirst = &removeFirst;
    list->removeLast = &removeLast;

    list->tail = NULL;
}

/**
 * Destroys a Circularly Linked List instance by garbage collecting all
 * linked nodes
 * @param list the list to be destroyed
 */
void CircularlyLinkedListDestroy(CircularlyLinkedList *list)
{
    CircularlyLinkedNode *current = list->tail;
    for (size_t i = 0; i < list->size; i++) {
        CircularlyLinkedNode *temp = current->next;
        free(current);
        current = temp;
    }
}