#include "list.h"

void	node_add_start(float data, Node **head) {
	Node *n;

    n = new Node();
    n->data = data;
    if (head != NULL)
        n->next = *head;
    else
        n->next = NULL;
    *head = n;
}
