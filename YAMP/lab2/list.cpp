#include "flight.h"

static void ft_strcpy(string to, char *from)
{
	int i = 0;

	while (from[i] != '\0')
	{
		to += from[i];
		i++;
	}
}

list::list()
{
	head = NULL;
}

bool list::is_empty()
{
	return head == NULL;
}

Node *list::add_front(int data)
{
	Node *n;

	n = new Node();
	n->id = data;
	n->prev = NULL;
	if (is_empty())
		n->next = NULL;
	else
	{
		n->next = head;
		head->prev = n;
	}
	head = n;
	return n;
}

Node *list::add_back(int data)
{
	Node *n;
	Node *tmp;

	tmp = head;
	n = new Node();
	n->id = data;
	n->next = NULL;
	n->prev = NULL;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	if (head != NULL)
	{
		tmp->next = n;
		n->prev = tmp;
	}
	else
		head = n;
	return n;
}

void list::del(Node *&node)
{
	Node *tmp;

	if (node != NULL && !is_empty())
	{
		tmp = node;
		if (node->prev != NULL)
			node->prev->next = node->next;
		if (node->next != NULL)
			node->next->prev = node->prev;
		if (node == head)
			head = head->next;
		delete tmp;
	}
}

void list::del()
{
	while (head != NULL)
		del(head);
}

void list::del_front()
{
	Node *tmp;

	if (!is_empty())
	{
		tmp = head;
		head = head->next;
		if (!is_empty())
			head->prev = NULL;
		delete tmp;
	}
}

void list::del_back()
{
	Node *tmp = head;

	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	if (!is_empty())
	{
		if (tmp->prev != NULL)
			tmp->prev->next = NULL;
		if (tmp == head)
			head = NULL;
		delete tmp;
	}
}

void list::print()
{
	Node *a = head;

	if (a == NULL)
		cout << "empty\n";
	while (a != NULL)
	{
		cout << "id: " << a->id << endl;
		cout << a->f.toString() << endl;
		a = a->next;
	}
}

void list::print(Date d)
{
	Node *a = head;
	Date date;

	if (a == NULL)
		cout << "empty";
	while (a != NULL)
	{
		date = a->f.getArrive();
		if (!date.isLater(d))
		{
			cout << "id: " << a->id << endl;
			cout << a->f.toString() << endl;
		}
		a = a->next;
	}
}

void list::print(int d)
{
	Node *a;

	a = find(d);
	if (a == NULL)
	{
		cout << "no one\n";
		return;
	}
	cout << "id: " << a->id << endl;
	cout << a->f.toString() << endl;
}

void list::print_in_file(string file)
{
	ofstream fout;
	Node *s = head;

	fout.open(file);
	while (s != NULL)
	{
		cout << "id: " << s->id << endl;
		cout << s->f.toString() << endl;
		s = s->next;
	}
	fout << endl;
	fout.close();
}

int list::read_from_file(string file)
{
	ifstream fin;
	char buff[50];
	Node *curr;
	int n;

	// open file & getting line
	fin.open(file);
	fin.getline(buff, 50);

	// getting number of flights
	n = atoi(buff);

	// parsing data
	for (int k = 0; k < n; k++)
	{
		curr = add_back(k);

		// from
		fin.getline(buff, 50);
		curr->f.setFrom(buff);

		// to
		fin.getline(buff, 50);
		curr->f.setTo(buff);

		// date leave
		fin.getline(buff, 50);
		if (!curr->f.setLeave(buff))
		{
			del(curr);
			curr = NULL;
		}

		// date arrive
		fin.getline(buff, 50);
		if (curr != NULL && !curr->f.setArrive(buff))
		{
			del(curr);
			curr = NULL;
		}
	}

	// close file
	fin.close();
	return 1;
}

void list::swap_nodes(Node *&a, Node *&b)
{
	Node *tmp;

	tmp = a;
	a = b;
	b = tmp;
}

void list::near_swap(Node *n1, Node *n2)
{
	n2->prev = n1->prev;
	n1->prev = n2;
	n1->next = n2->next;
	n2->next = n1;
	if (n2->prev != NULL)
		n2->prev->next = n2;
	if (n1->next != NULL)
		n1->next->prev = n1;
}

void list::swap(Node *n1, Node *n2)
{
	if (n1 != NULL && n2 != NULL)
	{
		// n1 near n2
		if (n1->next == n2)
			near_swap(n1, n2);
		else if (n2->next == n1)
			near_swap(n2, n1);
		else // n1 is not near n2
		{
			if (n1->prev != NULL)
				n1->prev->next = n2;
			if (n2->prev != NULL)
				n2->prev->next = n1;
			if (n1->next != NULL)
				n1->next->prev = n2;
			if (n2->next != NULL)
				n2->next->prev = n1;
			swap_nodes(n1->prev, n2->prev);
			swap_nodes(n1->next, n2->next);
		}

		// head change
		if (n1 == head)
			head = n2;
		else if (n2 == head)
			head = n1;
	}
}

Node *list::find(int i)
{
	Node *curr = head;

	while (curr != NULL)
	{
		if (curr->id == i)
			return curr;
		curr = curr->next;
	}
	return NULL;
}

void list::sort_date()
{
	Node *l1 = head;
	Node *l2 = head;
	Date date;

	while (l1 != NULL && l1->next != NULL)
	{
		l2 = l1->next;
		while (l2 != NULL)
		{
			date = l1->f.getArrive();
			if (!date.isLater(l2->f.getArrive()))
			{
				swap(l1, l2);
				swap_nodes(l1, l2);
			}
			l2 = l2->next;
		}
		l1 = l1->next;
	}
}

int list::count()
{
	Node *tmp = head;
	int i = 0;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return i;
}

int list::countFrom(string str)
{
	Node *a = head;
	string from;
	int i = 0;

	while (a != NULL)
	{
		from = a->f.getFrom();
		if (from == str)
			i++;
		a = a->next;
	}
	return i;
}

int list::countTo(string str)
{
	Node *a = head;
	string to;
	int i = 0;

	while (a != NULL)
	{
		to = a->f.getTo();
		if (to == str)
			i++;
		a = a->next;
	}
	return i;
}

void list::test()
{
	del();
}

bool list::edit(int id)
{
	string str;
	int n;
	char buff[50];
	Date d;
	Node* node = find(id);

	if (node == NULL)
		return 0;
	cin >> str;
	node->f.setFrom(str.c_str());
	cin >> str;
	node->f.setTo(str.c_str());
	cin >> n;
	d.setD(n);
	cin >> n;
	d.setM(n);
	cin >> n;
	d.setY(n);
	node->f.setArrive(d);

	cin >> n;
	d.setD(n);
	cin >> n;
	d.setM(n);
	cin >> n;
	d.setY(n);
	node->f.setLeave(d);

	return 1;
}

void Flight::setLeave(Date d)
{
	if (d.checkDate())
		leave.setDate(d);
}

void Flight::setArrive(Date d)
{
	if (d.checkDate())
		arrive.setDate(d);
}
