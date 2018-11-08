/**
 * @file linked_queue.h
 * @author Nikhil Milind
 *
 * A structure that contains a circularly linked queue of pointers.
 * No safety checking occurs on any operations to optimize speed,
 * so it is up to the user to check for out-of-bounds exceptions.
 */

#include <stdlib.h>
#include "../list/circularly_linked_list.h"

#ifndef DATA_STRUCTURES_LINKED_QUEUE
#define DATA_STRUCTURES_LINKED_QUEUE

struct linked_queue
{
    CircularlyLinkedList *list;

    void (*enqueue) (struct linked_queue *queue, void *value);
    void * (*dequeue) (struct linked_queue *queue);
    void * (*front) (struct linked_queue *queue);
    size_t (*size) (struct linked_queue *queue);
};

typedef struct linked_queue LinkedQueue;

extern void LinkedQueueConstruct(LinkedQueue *queue);

extern void LinkedQueueDetroy(LinkedQueue *queue);

#endif
