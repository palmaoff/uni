#include "list.h"
#include <fstream>

int number_of_nodes()
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

void list_input(Node *&node, int count)
{
	float n;

	cout << "Enter nodes for list:" << endl;
	for (int i = 0; i < count; i++)
	{
		cin >> n;
		add_end(node, n);
	}
}

void lists_from_file(Node *&a, Node *&b)
{
	char c;
	ifstream fin;
	char buff[50]; 

	fin.open("put_in");
	fin.getline(buff, 50);
	cout << buff << endl;
	fin.getline(buff, 50);
	cout << buff << endl;
	fin.close();
}

int main()
{
	Node *a;
	Node *b;
	float n;
	char c;
	ofstream out;

	list_init(a);
	list_init(b);

	cout << "file (f) or input (i): ";
	while (c != 'i' && c != 'f')
		cin >> c;
	if (c == 'i')
	{
		list_input(a, number_of_nodes());
		list_input(b, number_of_nodes());
	}
	if (c == 'f')
	{
		lists_from_file(a, b);
	}
	cout << "list 1: ";
	list_print(a);
	cout << "list 2: ";
	list_print(b);
	cout << "1 + 2: ";
	list_print(list_new_sort(a, b));

	list_del(a);
	list_del(b);
	return (0);
}
