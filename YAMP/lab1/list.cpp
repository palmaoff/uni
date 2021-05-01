#include "list.h"
#include <fstream>

list::list()			{	init();					}
void list::init()		{	head = NULL;			}
bool list::is_empty()	{	return head == NULL;	}

void list::add_start(float data)
{
	Node *n;

	n = new Node();
	n->data = data;
	if (head != NULL)
		n->next = head;
	else
		n->next = NULL;
	head = n;
}

void list::add_end(float data)
{
	Node *n;
	Node *tmp;

	tmp = head;
	n = new Node();
	n->data = data;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	if (head != NULL)
		tmp->next = n;
	else
		head = n;
}

void list::add(Node *&node, float data)
{
	Node *n;

	n = new Node();
	n->data = data;
	if (node != NULL)
	{
		n->next = node->next;
		node->next = n;
	}
	else
		n->next = NULL;
}

void list::print()
{
	Node *a = head;


	while (a != NULL)
	{
		cout << a->data;
		a = a->next;
		if (a != NULL)
			cout << "->";
	}
	cout << endl;
}

int list::count()
{
	Node* tmp = head;
	int i = 0;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return i;
}

void list::del(Node *&node)
{
	Node *tmp;
	if (node != NULL)
	{
		tmp = node;
		node = node->next;
		delete tmp;
	}
}

void list::del()
{
	while (head != NULL)
		del(head);
}

bool list::is_sort()
{
	Node *tmp = head;

	if (tmp == NULL)
		return 1;
	int i = head->data;
	while (tmp != NULL)
	{
		if (tmp->data >= i)
		{
			i = tmp->data;
			tmp = tmp->next;
		}
		else
			return 0;
	}
	return 1;
}

list list::new_sort(list l)
{
	list curr;
	Node *l1 = head;
	Node *l2 = l.head;

	if (!this->is_sort() && !l.is_sort())
		return curr;
	if (l1 == NULL && l2 == NULL)
		return curr;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->data > l2->data)
		{
			curr.add_end(l2->data);
			l2 = l2->next;
		}
		else
		{
			curr.add_end(l1->data);
			l1 = l1->next;
		}
	}
	while (l1 != NULL)
	{
		curr.add_end(l1->data);
		l1 = l1->next;
	}
	while (l2 != NULL)
	{
		curr.add_end(l2->data);
		l2 = l2->next;
	}
	return curr;
}

void	list::print_in_file()
{
	ofstream fout;
	Node *s = head;

	fout.open("put_out");
	while (s != NULL)
	{
		fout << s->data;
		s = s->next;
		if (s != NULL)
			fout << "->";
	}
	fout << endl;
	fout.close();
}
