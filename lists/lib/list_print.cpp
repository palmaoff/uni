#include "list.h"

void	list_print(List *a) {
	while (a != NULL) {
		cout << a->data;
		a = a->next;
	}
}
