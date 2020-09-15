#include "list.h"

void	list_print(Node *a) {
	while (a != NULL) {
		cout << a->data;
		a = a->next;
	}
}
