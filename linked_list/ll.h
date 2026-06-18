
typedef struct Node
{
    int data;
    struct Node* next;
} Node_t;

Node_t* create_node(int data);
void print_list(Node_t* head);
Node_t* insert_front(Node_t* head, int data);