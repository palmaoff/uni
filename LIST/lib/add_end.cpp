#include "list.h"

void	add_end(Node* &head, float data) {
	Node *n;
    Node *tmp;

    tmp = head;
    n = new Node();
    n->data = data;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = n;
}
