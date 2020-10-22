#include "list.h"

void list_init(Node *&head)
{
	head = NULL;
}

void print_list(Node *head)
{
	while (head != NULL)
	{
		cout << head->inf;
		if (head->next != NULL)
			cout << "->";
		head = head->next;
	}
	cout << endl;
}

void add_end(Node *&head, int inf)
{
	Node *new_node;

	new_node = new Node;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->inf = inf;

	if (head != NULL)
	{
		Node *curr = head;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new_node;
		new_node->prev = curr;
	}
	else
		head = new_node;
}

void del(Node *&head)
{
	Node *curr;

	while (head != NULL)
	{
		curr = head;
		head = head->next;
		delete curr;
	}
}

int del_first(Node *&head)
{
	if (head != NULL)
	{
		Node *tmp = head;
		head = head->next;
		if (head != NULL)
			head->prev = NULL;
		delete tmp;
	}
	else
		return 0;
	return 1;
}

int count_k(Node *head, int k)
{
	int i = 0;
	while (head != NULL)
	{
		if (head->inf > k)
			i++;
		head = head->next;
	}
	return i;
}
