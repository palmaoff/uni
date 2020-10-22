#include "list.h"

int main()
{
	int n;
	int k;
	Node* list;
	char c;

	list_init(list);
	cout << "Enter number of elements: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> k;
		add_end(list, k);
		
	}
	print_list(list);

	cout << "Enter k: ";
	cin >> k;
	cout << "Nubmber of elements > k: " << count_k(list, k) << endl;

	cout << "add at the end: " << endl;
	cin >> k;
	add_end(list, k);
	print_list(list);

	c = 'y';
	while (list != NULL && c != 'n')
	{
		cout << "delete first(y, n)? ";
		cin >> c;
		if (c == 'y')
			del_first(list);
		print_list(list);
	}
	del(list);
	return 0;
}
