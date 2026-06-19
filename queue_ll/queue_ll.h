#ifndef QUEUE_LL_H
#define QUEUE_LL_H

#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

typedef struct
{
    Node* front;
    Node* rear;
} Queue;

void init_queue(Queue* q);
bool is_empty(Queue* q);
void enqueue(Queue* q, int data); // add an element to the rear
int dequeue(Queue* q); // removes an element from the front
int peek(Queue* q);
void print_queue(Queue* q);

#endif