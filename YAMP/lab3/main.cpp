#include "tree.h"

int main()
{
	Tree t;
	int n;
	int data;
	string str = "";

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		t.add(data);
	}
	t.print();

	while (str != "q")
	{
		cin >> str;
		if (str == "p")
			t.print();
		if (str == "p2")
			t.print_2();
		if (str == "p3")
			t.print_3();
		if (str == "f")
		{
			cin >> n;
			if (t.find(n) != NULL)
				cout << "yes" << endl;
			else
				cout << "no";
		}
		if (str == "a")
		{
			cin >> n;
			t.add(n);
		}
		if (str == "d")
		{
			cin >> n;
			t.del(n);
		}
		if (str == "l")
			t.del();
		if (str == "m")
		{
			if ((n = t.max_odd()) != 0)
				cout << "max odd: " << n << endl;
		}
		cout << "q(quit) p(prind) d(del) l(del all) a(add) f(find) m(max odd)\n";
	}

	return 0;
}
