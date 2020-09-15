#include "list.h"

Node	*node_add_end(float data, Node *head) {
	Node *n;
    Node *tmp;

    tmp = head;
    n = new Node();
    n->data = data;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = n;
    return head;
}
