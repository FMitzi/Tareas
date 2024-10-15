/*
    queue.c
*/

#include <stdlib.h>
#include <string.h>
#include "queue.h"

/*
    Initialize the queue
*/
void queue_init(Queue *queue, void (*destroy)(void *data)) {
    queue->size = 0;
    queue->destroy = destroy;
    queue->head = NULL;
    queue->tail = NULL;
}

/*
    Destroy the queue
*/
void queue_destroy(Queue *queue) {
    void *data;

    while (queue_size(queue) > 0) {
        if (queue_dequeue(queue, &data) == 0 && queue->destroy != NULL) {
            queue->destroy(data);
        }
    }

    memset(queue, 0, sizeof(Queue));
}

/*
    Enqueue an element to the queue
*/
int queue_enqueue(Queue *queue, const void *data) {
    QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
    if (new_node == NULL) return -1;

    new_node->data = (void *)data;
    new_node->next = NULL;

    if (queue_size(queue) == 0) {
        queue->head = new_node;
    } else {
        queue->tail->next = new_node;
    }

    queue->tail = new_node;
    queue->size++;

    return 0;
}

/*
    Dequeue an element from the queue
*/
int queue_dequeue(Queue *queue, void **data) {
    if (queue_size(queue) == 0) return -1;

    QueueNode *old_node = queue->head;
    *data = old_node->data;

    queue->head = old_node->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    free(old_node);
    queue->size--;

    return 0;
}
