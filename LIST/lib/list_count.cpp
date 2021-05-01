#include "list.h"

int    list_count(Node* head)
{
	int i = 0;

	while (head != NULL) {
		head = head->next;
		i++;
	}
	return i;
}