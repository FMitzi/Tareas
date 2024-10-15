/*
    queue.h
*/
#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

/*
    Node structure for the queue
*/
typedef struct QueueNode_ {
    void *data;
    struct QueueNode_ *next;
} QueueNode;

/*
    Queue structure
*/
typedef struct Queue_ {
    int size;
    void (*destroy)(void *data);
    QueueNode *head;
    QueueNode *tail;
} Queue;

/*
    Public interfaces
*/
void queue_init(Queue *queue, void (*destroy)(void *data));
void queue_destroy(Queue *queue);
int queue_enqueue(Queue *queue, const void *data);
int queue_dequeue(Queue *queue, void **data);

/*
    Macros
*/
#define queue_peek(queue) ((queue)->head == NULL ? NULL : (queue)->head->data)
#define queue_size(queue) ((queue)->size)

#endif
