#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

Node_t* create_node(int data)
{
    Node_t* node = malloc(sizeof(Node_t));
    if (!node) perror("Error! no node made");
    node->data = data;
    node->next = NULL;
}

void print_list(Node_t* head)
{
    while(head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
}

Node_t* insert_front(Node_t* head, int data)
{
    // create new node
    Node_t* new_node = create_node(data);

    // check if head exists
    if (!head) perror("Error!");
    
}

int main()
{
    Node_t* first_node = create_node(10);
    first_node->next = create_node(20);
    first_node->next->next = create_node(30);

    print_list(first_node);
}
