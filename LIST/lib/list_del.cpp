#include "list.h"

void    list_del(Node* &node)
{
	while (node != NULL) {
		node_del(node);
	}
}
