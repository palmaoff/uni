#include "Fraction.h"

int main() {
	Fraction a;
	Fraction b;
	Fraction c;

	cout << "default: ";
	a.print();

	a.set(-12, 5);
	b.set(1, 2);
	cout << "set a: ";
	a.print();
	cout << "set b: ";
	b.print();

	c = a.mult(b);
	cout << "a * b: ";
	c.print();

	c = a.sum(b);
	cout << "a + b: ";
	c.print();

	c = a.sub(b);
	cout << "a - b: ";
	c.print();

	cout << "a > b: " << a.cmp(b);	
	return (0);
}
