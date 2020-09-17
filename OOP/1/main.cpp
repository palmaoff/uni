#include "Fraction.h"

int main() {
	Fraction a;
	Fraction b;
	Fraction c;
	int n;
	size_t d;

	cout << "default: ";
	a.print();
	b.print();

	cout << "set a: ";
	cin >> n >> d;
	a.set(n, d);
	a.print();
	cout << "set b: ";
	cin >> n >> d;
	b.set(n, d);
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

	cout << "a > b: " << a.cmp(b) << endl;

	string s = a.toString();
	cout << "a.toString: " << s << endl;
 
	return (0);
}
