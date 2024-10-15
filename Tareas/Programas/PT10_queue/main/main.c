/*
    main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*
    Print the queue elements
*/
static void print_queue(const Queue *queue) {
    QueueNode *node = queue->head;
    int i = 0;

    fprintf(stdout, "Queue size is %d\n", queue_size(queue));
    while (node != NULL) {
        fprintf(stdout, "queue[%03d]=%d\n", i, *(int *)node->data);
        node = node->next;
        i++;
    }
}

/*
    Enqueue an integer to the queue
*/
void enqueue_integer(Queue *queue, int value) {
    int *data = (int *)malloc(sizeof(int));
    if (data == NULL) return;

    *data = value;
    if (queue_enqueue(queue, data) != 0) {
        free(data);
    }
}

/*
    Dequeue an integer from the queue
*/
void dequeue_integer(Queue *queue) {
    int *data;
    if (queue_dequeue(queue, (void **)&data) == 0) {
        printf("Dequeued: %d\n", *data);
        free(data);
    } else {
        printf("Queue is empty, cannot dequeue.\n");
    }
}

int main(int argc, char *argv[]) {
    Queue queue;
    int i, value;

    // Initialize the queue
    queue_init(&queue, free);

    // Enqueue elements from program arguments
    for (i = 1; i < argc; ++i) {
        value = atoi(argv[i]);
        enqueue_integer(&queue, value);
    }

    print_queue(&queue);

    // Enqueue more elements
    enqueue_integer(&queue, 54);
    enqueue_integer(&queue, 73);

    print_queue(&queue);

    // Dequeue some elements
    dequeue_integer(&queue);
    dequeue_integer(&queue);

    print_queue(&queue);

    // Peek at the front of the queue
    int *front = queue_peek(&queue);
    if (front != NULL) {
        printf("Front of the queue: %d\n", *front);
    } else {
        printf("Queue is empty.\n");
    }

    // Destroy the queue
    fprintf(stdout, "Destroying the queue\n");
    queue_destroy(&queue);

    return 0;
}
