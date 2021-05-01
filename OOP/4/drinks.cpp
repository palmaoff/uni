#include "drinks.h"

Drink::Drink()
{
	currtemp = 18;
	TasteGood();
}

Drink::Drink(int temp)
{
	currtemp = temp;
	TasteGood();
}

void Drink::set(int temp)
{
	currtemp = temp;
	TasteGood();
}

void Drink::setTaste(string str)
{
	taste = str;
}

string Drink::getTaste()
{
	return taste;
}

int Drink::getTemp()
{
	return currtemp;
}

void Drink::TasteGood() // 0
{
	if (currtemp > 15 && currtemp < 25)
		taste = "good";
	else if (currtemp >= 100)
		taste = "water is boiling";
	else if (currtemp <= 0)
		taste = "ice";
	else
		taste = "not so good";
}

void Tea::TasteGood() // 1
{
	int currtemp = getTemp();
	if (currtemp < 100 && currtemp > 80)
		setTaste("good");
	else if (currtemp <= 80)
		setTaste("you need more temperature for your Tea");
	else if (currtemp >= 100)
		setTaste("water is boiling");
}

void PocketTea::TasteGood() // 2
{
	int currtemp = getTemp();
	if (currtemp < 100 && currtemp > 80)
		setTaste("good");
	else if (currtemp <= 80)
		setTaste("you need more temperature for your Tea");
	else if (currtemp >= 100)
		setTaste("too hot, boiling Tea");
}

void Coffee::TasteGood() // 3
{
	int currtemp = getTemp();
	if (currtemp < 100 && currtemp > 80)
		setTaste("good");
	else if (currtemp <= 80)
		setTaste("you need more temperature for your coffee");
	else if (currtemp >= 100)
		setTaste("Coffee ran away");
}

void MulledWine::TasteGood() // 4
{
	int currtemp = getTemp();
	if (currtemp < 100 && currtemp > 80)
		setTaste("aeee");
	else if (currtemp <= 80)
		setTaste("temperature is not high enough");
	else if (currtemp >= 100)
		setTaste("too hot");
}

void OrangeJuice::TasteGood() // 5
{
	int currtemp = getTemp();
	if (currtemp < 25 && currtemp > 15)
		setTaste("good");
	else if (currtemp <= 5)
		setTaste("cold");
	else if (currtemp >= 100)
		setTaste("too too hot");
	else
		setTaste("bad Juice");
}

void f_Tea()
{
	Tea d;
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

// functions for interface
void f_PocketTea()
{
	PocketTea d;
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

void f_Coffee()
{
	Coffee d;
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

void f_MulledWine()
{
	MulledWine d;
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

void f_OrangeJuice()
{
	OrangeJuice d;
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
