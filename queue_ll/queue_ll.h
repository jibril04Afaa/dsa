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
void enqueue(Queue* q, int data);
int dequeue(Queue* q);
int peek(Queue* q);
void print_queue(Queue* q);

#endif