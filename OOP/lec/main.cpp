#include "vec.h"

int main() {
	vec a(4, 3, 2);
	vec b(1, 2, 3);
	vec c;

	cout << "a: ";
	a.print();

	cout << "b: ";
	b.print();

	cout << "a * b: " << a.scalar(b)  << endl;

	c = a + b;
	cout << "a + b: ";
	c.print();

	a++;
	cout << "a++: ";
	a.print();

	return 0;
}