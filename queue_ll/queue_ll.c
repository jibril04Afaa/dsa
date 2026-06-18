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
    if(q->front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(Queue* q, int data)
{
    // create a new node
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    /* add new node */
    // when queue is empty, both front and back become the new node
    if (is_empty(q))
    {
        q->front = new_node;
        q->rear = new_node;
    }
    else
    {
        /* if not empty, add new node to the back & update rear */
        q->front->next = new_node;
        q->rear = new_node;
    }   
}


int dequeue(Queue* q);
int peek(Queue* q);
void print_queue(Queue* q)
{
    while (q->rear != NULL)
    {
        // traverse queue from the rear
        printf("%d->", q->rear);
    }
    
}

int main()
{
    printf("Queue: \n");

    Queue main_q;
    init_queue(&main_q);
    enqueue(&main_q, 7);
    enqueue(&main_q, 8);

    print_queue(&main_q);

    return 0;
}