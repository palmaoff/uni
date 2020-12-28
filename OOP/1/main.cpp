/*
Реализовать модель дробного числа и
базовых опреаций над дробными числами
*/

#include "Fraction.h"

int main() {
	Fraction a;
	Fraction b;
	Fraction c;
	int n;
	int d;

	cout << "default: " << endl << "a: ";
	a.print();
	cout << "b: ";
	b.print();

	cout << "set a: ";
	cin >> n >> d;
	a.set(n, d);
	a.print();
	cout << "set b: ";
	cin >> n >> d;
	b.set(n, d);
	b.print();

	cout << "a.getN: " << a.getN() << endl;
	cout << "b.getN: " << b.getN() << endl;

	c = a.mult(b);
	cout << "a * b: ";
	c.print();

	c = a.sum(b);
	cout << "a + b: ";
	c.print();

	c = a.sub(b);
	cout << "a - b: ";
	c.print();

	c = a.div(b);
	cout << "a / b: ";
	c.print();

	cout << "a > b: " << a.cmp(b) << endl;

	string s = a.toString();
	cout << "a.toString: " << s << endl;

	s = b.toString();
	cout << "b.toString: " << s << endl;
 
	return (0);
}
