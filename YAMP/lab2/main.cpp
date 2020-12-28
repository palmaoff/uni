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

	while (str != "q")
	{
		cout << "q(quit) d(date) i(id) s(sorted) t(test)\n";
		cin >> str;
		if (str == "d")
		{
			cout << "date:";
			d.read();
			cout << endl;
			if (d.checkDate())
				l.print(d);
			else
				cout << "incorrect date\n";
			
		}
		if (str == "i")
		{
			cin >> n;
			cout << endl;
			l.print(n);
		}
		if (str == "s")
		{
			l.sort_date();
			cout << "sorted:" << endl << endl;
			l.print();
		}
		if (str == "t")
			l.test();
		if (str == "p")
			l.print();
		if (str == "r")
			l.del();
		if (str == "a")
		{
			cin >> n;
			l.add_front(n);
		}
		if (str == "e")
		{
			cin >> n;
			if (!l.edit(n))
				cout << "there is no such flight";
		}
	}
	return 0;
}
