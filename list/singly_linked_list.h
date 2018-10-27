/**
 * @file array_list.h
 * @author Nikhil Milind
 *
 * A structure that contains a Singly-Linked list of pointers.
 * No safety checking occurs on any operations to optimize speed,
 * so it is up to the user to check for out-of-bounds exceptions.
 */

#include <stdlib.h>

#ifndef DATA_STRUCTURES_SINGLY_LINKED_LIST
#define DATA_STRUCTURES_SINGLY_LINKED_LIST

struct singly_linked_node
{
    struct singly_linked_node *next;
    void *data;
};

typedef struct singly_linked_node SinglyLinkedNode;

struct singly_linked_list
{
    size_t size;
    SinglyLinkedNode *head;

    void (*set) (struct singly_linked_list *list, const size_t index, void *value);
    void * (*get) (struct singly_linked_list *list, const size_t index);

    void (*add) (struct singly_linked_list *list, const size_t index, void *value);
    void (*addFirst) (struct singly_linked_list *list, void *value);
    void (*addLast) (struct singly_linked_list *list, void *value);

    void * (*remove) (struct singly_linked_list *list, const size_t index);
    void * (*removeFirst) (struct singly_linked_list *list);
    void * (*removeLast) (struct singly_linked_list *list);
};

typedef struct singly_linked_list SinglyLinkedList;

extern void SinglyLinkedListConstruct(SinglyLinkedList *list);

extern void SinglyLinkedListDestroy(SinglyLinkedList *list);

#endif