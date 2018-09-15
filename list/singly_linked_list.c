#include "singly_linked_list.h"
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
static void set(SinglyLinkedList *list, const size_t index, void *value)
{
    SinglyLinkedNode *current = &list->head;
    for (size_t i = 0; i <= index; i++) {
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
static void * get(SinglyLinkedList *list, const size_t index)
{
    SinglyLinkedNode *current = &list->head;
    for (size_t i = 0; i <= index; i++) {
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
static void add(SinglyLinkedList *list, const size_t index, void *value)
{
    SinglyLinkedNode *current = &list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    SinglyLinkedNode *insert = (SinglyLinkedNode *) malloc(sizeof(SinglyLinkedNode));
    *insert = (SinglyLinkedNode) { .data = value, .next = current->next };
    current->next = insert;
    list->size++;
}

/**
 * Add a pointer at the beginning of the list.
 * @param list the list to augment
 * @param value the value to add
 */
static void addFirst(SinglyLinkedList *list, void *value)
{
    list->add(list, 0, value);
}

/**
 * Add a pointer to the end of the list.
 * @param list the list to augment
 * @param value the value to add
 */
static void addLast(SinglyLinkedList *list, void *value)
{
    list->add(list, list->size, value);
}

/**
 * Remove and return the pointer at the specified index.
 * @param list the list to augment
 * @param index the index to retrieve the pointer from
 * @return the pointer at the index specified
 */
static void * remove(SinglyLinkedList *list, const size_t index)
{
    SinglyLinkedNode *current = &list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    SinglyLinkedNode *insert = current->next;
    current->next = current->next->next;
    list->size--;
    return insert->data;
}

/**
 * Remove the first pointer in the list and return it
 * @param list the list to augment
 * @return the pointer that is removed
 */
static void * removeFirst(SinglyLinkedList *list)
{
    return list->remove(list, 0);
}

/**
 * Remove the last pointer in the list and return it
 * @param list the list to augment
 * @return the pointer that is removed
 */
static void * removeLast(SinglyLinkedList *list)
{
    return list->remove(list, list->size - 1);
}

/*
 * Construction / Destruction
 */

/**
 * Constructs a new Singly Linked List instance
 * with a sentinel node at the front of the list.
 * @param list the list to be constructed
 */
void SinglyLinkedListConstruct(SinglyLinkedList *list)
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

    list->head = (SinglyLinkedNode) { .next = NULL, .data = NULL };
}

/**
 * Destroys a Singly Linked List instance by garbage collecting all
 * linked nodes
 * @param list the list to be destroyed
 */
void SinglyLinkedListDestroy(SinglyLinkedList *list)
{
    SinglyLinkedNode *current = &list->head;
    while (current->next != NULL) {
        SinglyLinkedNode *temp = current->next;
        free(current->next);
        current = temp;
    }
}