#include "list.h"

void    node_del(Node* &node) {
	Node* tmp;
	if (node != NULL) {
		tmp = node;
		node = node->next;
		delete tmp;
	}
}
