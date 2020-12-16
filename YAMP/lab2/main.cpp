#include "flight.h"

int main()
{
	list	l;
	Date	d;
	int		n;
	string	str = "";

	if (!l.read_from_file("in.txt"))
	{
		cout << "input file error" << endl;
		return 0;
	}
	l.print();
	// l.test();
	l.sort_date();
	cout << "sorted:" << endl << endl;
	l.print();

	while (str != "q")
	{
		cout << "q(quit) d(date) i(id)\n";
		cin >> str;
		if (str == "d")
		{
			cout << "date:";
			d.read();
			cout << endl;
			l.print(d);
		}
		if (str == "i")
		{
			cin >> n;
			cout << endl;
			l.print(n);
		}
	}

	return 0;
}
