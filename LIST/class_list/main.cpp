#include "list.h"
#include <string.h>
#include <fstream>

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

void	list_input(list &node, int count)
{
	float n;

	cout << "Enter nodes for list:" << endl;
	for (int i = 0; i < count; i++)
	{
		cin >> n;
		node.add_end(n);
	}
}

void	node_buff(list &node, char buff[50])
{
	int i = 0;

	while (buff[i] != '\0')
	{
		while (buff[i] == ' ')
			i++;
		node.add_end(atoi(&buff[i]));
		while (buff[i] != ' ' && buff[i] != '\0')
			i++;
	}
}

void	lists_from_file(list &a, list &b)
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

int		main()
{
	list	a;
	list	b;
	list	s;
	int		n;
	char	c;

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
	a.print();
	cout << "list 2: ";
	b.print();
	cout << "1 + 2: ";
	s = a.new_sort(b);
	s.print();

	// save in file
	cout << "save in file(y, n)? ";
	while (c != 'y' && c != 'n')
		cin >> c;
	if (c == 'y')
		s.print_in_file();

	// a.add_end(110);
	// a.print();
	// s = a.new_sort(b);
	// if (s.is_empty())
	// 	cout << "list is empty" << endl;

	cout << a.count() << endl;
	cout << b.count() << endl;

	a.del();
	s = a.new_sort(b);
	s.print();
	cout << a.count() << endl;
	cout << b.count() << endl;

	// clear memory
	// a.del();
	b.del();
	s.del();

	return (0);
}
