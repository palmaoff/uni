#include "tube.h"

Tube::Tube()
{
	d = 0;
	U = 0;
	B = 0;
	V = 0;
}

Tube::~Tube() { cout << "i am distructor" << endl; }

Tube::Tube(double d, double U, double B)
{
	if (d > 0)
		this->d = d / 100;
	if (U > 0)
		this->U = U / 1000;
	if (B > 0)
		this->B = B;
}

double	Tube::getD() { return d; }

double	Tube::getU() { return U; }

double	Tube::getB() { return B; }

double	Tube::getV() { return V; }

void Tube::set()
{
	tube_input();
	speed();
}

void	Tube::setD(double d)
{
	if (d > 0)
		this->d = d / 100;
	else
	{
		cout << "invalid parametr" << endl;
		this->d = 0;
	}
	speed();
}

void	Tube::setU(double U)
{
	if (U > 0)
		this->U = U / 1000;
	else
	{
		cout << "invalid parametr" << endl;
		this->U = 0;
	}
	speed();
}

void	Tube::setB(double B)
{
	if (B > 0)
		this->B = B;
	else
	{
		cout << "invalid parametr" << endl;
		this->B = 0;
	}
	speed();
}

string	Tube::toString() { return to_string(V); }

void	Tube::print()
{
	cout << "B[tesla]: " << B << endl;
	cout << "U[V] : " << U << endl;
	cout << "d[m]: " << d << endl;
}

void	Tube::tube_input()
{
	double tmp;
	cout << "set parameters: " << endl;

	cout << "B[tesla]: ";
	cin >> tmp;
	this->setB(tmp);

	cout << "U[mV]: ";
	cin >> tmp;
	this->setU(tmp);

	cout << "d[sm]: ";
	cin >> tmp;
	this->setD(tmp);
}

void    Tube::speed()
{
	if (U > 0 && B > 0 && d > 0)
		V = U / (B * d);
	else
		V = 0;
}

void tube_loop()
{
	Tube t;

	char c = 'y';
	while (c != 'n')
	{
		t.set();
		cout << endl;
		cout << "V: " << t.toString() << endl;
		cout << endl;
		t.print();
		cout << "Want to continue(y, n)? ";
		cin >> c;
	}
}
