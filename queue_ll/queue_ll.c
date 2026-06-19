#include "queue_ll.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void init_queue(Queue* q)
{
    q->front = NULL;
    q->rear = NULL;
}

bool is_empty(Queue* q)
{
    return q->front == NULL;
}

void enqueue(Queue* q, int data)
{
    // create new node
    Node* new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Allocation failed! \n");
        return;
    }
    new_node->data = data;
    new_node->next = NULL;

    // check if queue is empty
    if (is_empty(q))
    {
        // the front and back become the same node 
        q->front = new_node;
        q->rear = new_node;
    }

    // attach to rear
    else
    {
       q->rear->next = new_node;
       q->rear = new_node;
    }
}


int dequeue(Queue* q)
{
    if (is_empty(q))
    {
        // cannot dequeue from an empty queue
        printf("Queue empty, cannot dequeue!\n");
        return -1;
    }
    else
    {
        // temp variables to hold onto the old node so we can free it
        Node* temp = q->front;
        int data = temp->data;

        // remove from front - i.e, move front pointer to the next value
        q->front = q->front->next;

        // free the allocated temp! this was allocated in the enqueue function
        free(temp);

        return data; // RETURN the data we just dequeued
    }
}

int peek(Queue* q)
{
    if (is_empty(q))
    {
        printf("Queue is empty! Cannot peek \n");
        return -1;
    }
    else
    {
        return q->front->data;
    }
}

void print_queue(Queue* q)
{
    Node* current = q->front;
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
}

int main()
{
    /* driver code */
    Queue main_q;
    init_queue(&main_q);

    // add elements to the queue
    enqueue(&main_q, 10);
    enqueue(&main_q, 20);
    enqueue(&main_q, 30);
    enqueue(&main_q, 40);
    enqueue(&main_q, 50);
    enqueue(&main_q, 60);

    int val = dequeue(&main_q);
    printf("Value dequeued: %d\n", val);

    printf("Printed queue with linked list: \n");
    print_queue(&main_q);
    printf("\n");

    int pee = peek(&main_q);
    printf("Value peeked: %d\n", pee);

    return 0;
}