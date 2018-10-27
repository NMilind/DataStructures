#include "doubly_linked_list.h"
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
static void set(DoublyLinkedList *list, const size_t index, void *value)
{
    if (index > list->size / 2) {
        DoublyLinkedNode *current = list->tail;
        for (size_t i = list->size; i > index; i--) {
            current = current->prev;
        }
        current->data = value;
    }
    else {
        DoublyLinkedNode *current = list->head;
        for (size_t i = 0; i <= index; i++) {
            current = current->next;
        }
        current->data = value;
    }
}

/**
 * Returns the value of the pointer at a given index
 * @param list the list to query
 * @param index the index to query
 * @return the pointer at the given index
 */
static void * get(DoublyLinkedList *list, const size_t index)
{
    if (index > list->size / 2) {
        DoublyLinkedNode *current = list->tail;
        for (size_t i = list->size; i > index; i--) {
            current = current->prev;
        }
        return current->data;
    }
    else {
        DoublyLinkedNode *current = list->head;
        for (size_t i = 0; i <= index; i++) {
            current = current->next;
        }
        return current->data;
    }
}

/**
 * Add a pointer at the specified index.
 * @param list the list to be augmented
 * @param index the index at which to add a pointer
 * @param value the pointer to add
 */
static void add(DoublyLinkedList *list, const size_t index, void *value)
{
    DoublyLinkedNode *current = NULL;
    if (index > list->size / 2) {
        current = list->tail;
        for (size_t i = list->size; i >= index; i--) {
            current = current->prev;
        }
    }
    else {
        current = list->head;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
    }

    DoublyLinkedNode *insert = (DoublyLinkedNode *) malloc(sizeof(DoublyLinkedNode));
    *insert = (DoublyLinkedNode) { .data = value, .next = current->next, .prev = current };
    current->next = insert;
    insert->next->prev = insert;
    list->size++;
}

/**
 * Add a pointer at the beginning of the list.
 * @param list the list to augment
 * @param value the value to add
 */
static void addFirst(DoublyLinkedList *list, void *value)
{
    list->add(list, 0, value);
}

/**
 * Add a pointer to the end of the list.
 * @param list the list to augment
 * @param value the value to add
 */
static void addLast(DoublyLinkedList *list, void *value)
{
    list->add(list, list->size, value);
}

/**
 * Remove and return the pointer at the specified index.
 * @param list the list to augment
 * @param index the index to retrieve the pointer from
 * @return the pointer at the index specified
 */
static void * remove(DoublyLinkedList *list, const size_t index)
{
    DoublyLinkedNode *current = NULL;
    if (index > list->size / 2) {
        current = list->tail;
        for (size_t i = list->size; i >= index; i--) {
            current = current->prev;
        }
    }
    else {
        current = list->head;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
    }

    DoublyLinkedNode *insert = current->next;
    current->next = current->next->next;
    current->next->prev = current;
    list->size--;
    void *data = insert->data;
    free(insert);
    return data;
}

/**
 * Remove the first pointer in the list and return it
 * @param list the list to augment
 * @return the pointer that is removed
 */
static void * removeFirst(DoublyLinkedList *list)
{
    return list->remove(list, 0);
}

/**
 * Remove the last pointer in the list and return it
 * @param list the list to augment
 * @return the pointer that is removed
 */
static void * removeLast(DoublyLinkedList *list)
{
    return list->remove(list, list->size - 1);
}

/*
 * Construction / Destruction
 */

/**
 * Constructs a new Doubly Linked List instance
 * with a sentinel node at the front of the list.
 * @param list the list to be constructed
 */
void DoublyLinkedListConstruct(DoublyLinkedList *list)
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

    list->head = (DoublyLinkedNode *) malloc(sizeof(DoublyLinkedNode));
    *(list->head) = (DoublyLinkedNode) { .next = NULL, .data = NULL, .prev = NULL };
    list->tail = (DoublyLinkedNode *) malloc(sizeof(DoublyLinkedNode));
    *(list->tail) = (DoublyLinkedNode) { .next = NULL, .data = NULL, .prev = NULL };
    list->head->next = list->tail;
    list->tail->prev = list->head;
}

/**
 * Destroys a Doubly Linked List instance by garbage collecting all
 * linked nodes
 * @param list the list to be destroyed
 */
void DoublyLinkedListDestroy(DoublyLinkedList *list)
{
    DoublyLinkedNode *current = list->head;
    for (size_t i = 0; i < list->size; i++) {
        DoublyLinkedNode *temp = current->next;
        free(current->next);
        current = temp;
    }
    free(list->head);
}