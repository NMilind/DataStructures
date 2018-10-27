/**
 * @file circularly_linked_list.h
 * @author Nikhil Milind
 *
 * A structure that contains a circularly-linked list of pointers.
 * No safety checking occurs on any operations to optimize speed,
 * so it is up to the user to check for out-of-bounds exceptions.
 */

#include <stdlib.h>

#ifndef DATA_STRUCTURES_CIRCULARLY_LINKED_LIST
#define DATA_STRUCTURES_CIRCULARLY_LINKED_LIST

struct circularly_linked_node
{
    struct circularly_linked_node *next;
    void *data;
};

typedef struct circularly_linked_node CircularlyLinkedNode;

struct circularly_linked_list
{
    size_t size;
    CircularlyLinkedNode *tail;

    void (*set) (struct circularly_linked_list *list, const size_t index, void *value);
    void * (*get) (struct circularly_linked_list *list, const size_t index);

    void (*add) (struct circularly_linked_list *list, const size_t index, void *value);
    void (*addFirst) (struct circularly_linked_list *list, void *value);
    void (*addLast) (struct circularly_linked_list *list, void *value);

    void * (*remove) (struct circularly_linked_list *list, const size_t index);
    void * (*removeFirst) (struct circularly_linked_list *list);
    void * (*removeLast) (struct circularly_linked_list *list);
};

typedef struct circularly_linked_list CircularlyLinkedList;

extern void CircularlyLinkedListConstruct(CircularlyLinkedList *list);

extern void CircularlyLinkedListDestroy(CircularlyLinkedList *list);

#endif