#include "list.h"

void    add_node(Node* &node, float data)
{
    Node *n;

    n = new Node();
    n->data = data;
    if (node != NULL)
        n->next = node->next;
    else
        n->next = NULL;
    node = n;
}
