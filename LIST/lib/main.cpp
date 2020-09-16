#include "list.h"

int main() {
	Node *a;

	list_init(&a);
	node_add_start(6, &a);
	node_add_start(4, &a);
	node_add_start(3, &a);
	node_add_start(2, &a);
	node_add_start(1, &a);
	list_print(a);
	return (0);
}
