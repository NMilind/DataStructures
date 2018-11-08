#include "linked_queue.h"
#include "../list/circularly_linked_list.h"

/*
 * Instance Methods
 */
static void *enqueue(LinkedQueue *queue, void *value)
{

}

/*
 * Constructors / Destructors
 */

/**
 * Constructs a new instance of a Linked Queue.
 * @param queue the queue to construct
 */
void LinkedQueueConstruct(LinkedQueue *queue)
{
    CircularlyLinkedListConstruct(queue->list);
}

/**
 * Destroys an instance of a Linked Queue
 * @param queue the queue to destroy
 */
void LinkedQueueDestroy(LinkedQueue *queue)
{
    CircularlyLinkedListDestroy(queue->list);
}