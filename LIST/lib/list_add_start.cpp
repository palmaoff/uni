#include "list.h"

void	add_start(Node* &head, float data)
{
	Node *n;

    n = new Node();
    n->data = data;
    if (head != NULL)
        n->next = head;
    else
        n->next = NULL;
    head = n;
}
