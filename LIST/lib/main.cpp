#include "list.h"

int main() {
	Node *a;

	list_init(&a);
	add_start(a, 0);
	add_after(a, 6);
	add_after(a->next, 5);
	list_print(a);
	return (0);
}
