#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

Node* create_node(int data)
{
    Node* new_node = malloc(sizeof(Node));

    // malloc error check
    if (!new_node) perror("Failed to allocate");

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

Node* insert_front(Node* head, int data)
{
    // create a new node to add
    Node* to_add = create_node(data);

    /* point the new node's next to the current head*/
    to_add->next = head;

    return to_add;
}

Node* delete_front(Node* head)
{
    // verify list's emptiness
    if (head == NULL) perror("Cannot delete front");

    /* create a temp variable for head, because when we move 
    the pointer to the next node in the list, the previous 
    node will be sitting in memory with no pointer attached.*/
    Node* temp = head;

    // move the current head to the next 
    head = head->next;

    // finally, free the pointer for the old head
    free(temp);

    return head;
}

void print_list(Node* head)
{
    // start from head and print as long as head exists
    while (head != NULL)
    {
        printf("->%d", head->data);

        // move the pointer forward
        head = head->next;
    }
}

void free_list(Node* head)
{
    while (head != NULL)
    {
        Node* temp = head; // save the next pointer before freeing
        head = head->next; // move the pointer along the list
        free(temp);
    }   
}

Node* reverse_list(Node* head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    // check that head exists
    while (curr != NULL)
    {
        next = curr->next; // fill in the NULL next ptr to the head's (curr) next ptr
        curr->next = prev; // reverse LL's order

        /* even out the odds */
        prev = curr; // set prev to curr
        curr = next;
    }

    return prev; // prev is the new head after reversal
}


int main()
{
    /* driver code*/
    Node* head = create_node(10);

    head->next = create_node(20);
    head->next->next = create_node(30);
    head->next->next->next = create_node(40);
    head->next->next->next->next = create_node(50);
    head->next->next->next->next->next = create_node(60);
    head->next->next->next->next->next->next = create_node(70);

    head = insert_front(head, 67);
    head = delete_front(head);

    print_list(head);

    head = reverse_list(head);

    printf("\n Reversed: ");
    print_list(head);

    return 0;
}
