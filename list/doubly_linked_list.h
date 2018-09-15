/**
 * @file array_list.h
 * @author Nikhil Milind
 *
 * A structure that contains a Doubly-Linked List of pointers.
 * The pointers can be of any kind. No safety checking occurs on
 * any operations to optimize speed, so it is up to the user to
 * check for out-of-bounds exceptions.
 */

#include <stdlib.h>

#ifndef DATA_STRUCTURES_DOUBLY_LINKED_LIST
#define DATA_STRUCTURES_DOUBLY_LINKED_LIST

struct doubly_linked_node
{
    struct doubly_linked_node *next;
    void *data;
    struct doubly_linked_node *prev;
};

typedef struct doubly_linked_node DoublyLinkedNode;

struct doubly_linked_list
{
    size_t size;
    DoublyLinkedNode head;
    DoublyLinkedNode tail;

    void (*set) (struct doubly_linked_list *list, const size_t index, void *value);
    void * (*get) (struct doubly_linked_list *list, const size_t index);

    void (*add) (struct doubly_linked_list *list, const size_t index, void *value);
    void (*addFirst) (struct doubly_linked_list *list, void *value);
    void (*addLast) (struct doubly_linked_list *list, void *value);

    void * (*remove) (struct doubly_linked_list *list, const size_t index);
    void * (*removeFirst) (struct doubly_linked_list *list);
    void * (*removeLast) (struct doubly_linked_list *list);
};

typedef struct doubly_linked_list DoublyLinkedList;

extern void DoublyLinkedListConstruct(DoublyLinkedList *list);

extern void DoublyLinkedListDestroy(DoublyLinkedList *list);

#endif