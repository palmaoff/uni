/*
4
Реализовать класс «напитки» и не менее пяти наследников, среди которых должен
быть листовой чай, е и чай из пакетика. Предусмотреть случай, когда листовой
чай был подвергнут нагреву до температуры кипения воды (изменение вкуса и запаха
в соответствующем сообщении) и убегание кофе.
*/

#include "drinks.h"

void f_Water() // 0
{
	Drink d;
	int t;
	char c = 'y';

	while (c != 'n')
	{
		cout << "Enter temperature for your drink: ";
		cin >> t;
		d.set(t);
		cout << "Taste: " << d.getTaste() << endl;
		c = 0;
		cout << "Whant to continue? (y, n) ";
		while (c != 'y' && c != 'n')
			cin >> c;
	}
}

int main()
{
	string str;
	cout << "Water | OrangeJuice | MulledWine | Coffee | PocketTea | Tea\n";
	cout << "Choose your drink: ";
	cin >> str;
	if (str == "MulledWine")
		f_MulledWine();
	if (str == "Water")
		f_Water();
	if (str == "OrangeJuice")
		f_OrangeJuice();
	if (str == "Coffee")
		f_Coffee();
	if (str == "PocketTea")
		f_PocketTea();
	if (str == "Tea")
		f_Tea();

	return 0;
}