#include "queue_ll.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void init_queue(Queue* q)
{
    q->front = NULL;
    q->rear = NULL;
}

int is_empty(Queue* q)
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
        q->rear->data = new_node;
        q->rear->next = NULL;
    }

}
int dequeue(Queue* q);
int peek(Queue* q);
void print_queue(Queue* q);

int main()
{
    return 0;
}