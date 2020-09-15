#include "list.h"

Node	*node_add_start(float data, Node *head) {
	Node *n;

    n = new Node();
    n->data = data;
    n->next = head;
    return n;
}
