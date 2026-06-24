

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* create_node(int data);
Node* insert_front(Node* head, int data);
Node* delete_front(Node* head);
Node* delete_value(Node* head, int value);
void print_list(Node* head);
void free_list(Node* head);
Node* reverse_list(Node* head);