#include "list.h"

Node*	list_new_sort(Node* l1, Node* l2)
{
	Node* curr;

	list_init(curr);
	if (l1 == NULL && l2 == NULL)
		return NULL;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->data > l2->data)
		{
			add_end(curr, l2->data);
			l2 = l2->next;
		}
		else
		{
			add_end(curr, l1->data);
			l1 = l1->next;
		}
	}
	while (l1 != NULL)
	{
			add_end(curr, l1->data);
			l1 = l1->next;
	}
	while (l2 != NULL)
	{
			add_end(curr, l2->data);
			l2 = l2->next;
	}
	return curr;
}