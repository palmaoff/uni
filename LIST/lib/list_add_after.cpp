#include "list.h"

void    add_after(Node* node, float data)
{
	Node *n;

    n = new Node();
    n->data = data;
    if (node != NULL) {
        n->next = node->next;
        node->next = n;
    }
    else
        n->next = NULL;
}
