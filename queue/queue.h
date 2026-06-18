#include <stdbool.h>
#define MAX_SIZE 100


typedef struct Queue_t
{
    int front;
    int rear;
    int items[MAX_SIZE];
} Queue;

void init_queue(Queue* q);
bool is_empty(Queue* q);
bool is_full(Queue* q);
void enqueue(Queue* q, int data);
void dequeue(Queue* q);
int peek(Queue* q);
void print_queue(Queue* q);
