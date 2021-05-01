#include "list.h"
#include <string.h>

int		number_of_nodes()
{
	int count = 0;

	while (count <= 0)
	{
		cout << "Enter number of elements in list: ";
		cin >> count;
		if (count <= 0)
			cout << "number must be > 0" << endl;
	}
	return count;
}

void	list_input(Node *&node, int count)
{
	float n;

	cout << "Enter nodes for list:" << endl;
	for (int i = 0; i < count; i++)
	{
		cin >> n;
		add_end(node, n);
	}
}

void	node_buff(Node* &node, char buff[50])
{
	int i = 0;

	while (buff[i] != '\0')
	{
		while (buff[i] == ' ')
			i++;
		add_end(node, atoi(&buff[i]));
		while (buff[i] != ' ' && buff[i] != '\0')
			i++;
	}
}

void	lists_from_file(Node *&a, Node *&b)
{
	char c;
	ifstream fin;
	char buff[50];

	fin.open("put_in");
	fin.getline(buff, 50);
	node_buff(a, buff);
	fin.getline(buff, 50);
	node_buff(b, buff);
	fin.close();
}

void	print_in_file(Node* s)
{
	ofstream fout;

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

int		main()
{
	Node	*a;
	Node	*b;
	Node	*s;
	int		n;
	char	c;

	// initialization
	list_init(a);
	list_init(b);
	list_init(s);

	// file or console
	cout << "file (f) or console input (c): ";
	while (c != 'c' && c != 'f')
		cin >> c;
	if (c == 'c')
	{
		list_input(a, number_of_nodes());
		list_input(b, number_of_nodes());
	}
	if (c == 'f')
		lists_from_file(a, b);

	// lists & sort
	cout << "list 1: ";
	list_print(a);
	cout << "list 2: ";
	list_print(b);
	cout << "1 + 2: ";
	s = list_new_sort(a, b);
	list_print(list_new_sort(a, b));

	// save in file
	cout << "save in file(y, n)? ";
	while (c != 'y' && c != 'n')
		cin >> c;
	if (c == 'y')
		print_in_file(s);

	// clear memory
	list_del(a);
	list_del(b);
	list_del(s);

	return (0);
}
