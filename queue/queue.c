#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void init_queue(Queue* q)
{
    q->front = -1;
    q->rear = 0;
}

bool is_empty(Queue* q)
{
    if (q->front == -1 && q->rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_full(Queue* q)
{
    if (q->rear == MAX_SIZE)
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
    // check if empty
    if (!is_empty(q))
    {
        q->items[q->rear] = data;
        q->rear++;
    }
    else
    {
        printf("Queue is full! \n");
        return;
    }
}
void dequeue(Queue* q)
{
    if(is_empty(q))
    {
        printf("Queue is empty, cannot dequeue! \n");
        return;
    }
    q->front++;
}


int peek(Queue* q)
{
    if (is_empty(q))
    {
        printf("Queue is empty, cannot peek!");
        return -1;
    }
    return q->items[q->front + 1];
}
void print_queue(Queue* q)
{
    if (is_empty(q))
    {
        printf("Queue is empty, cannot print! \n");
    }

}

int main()
{
    printf("ququq\n");
    return 0;
}