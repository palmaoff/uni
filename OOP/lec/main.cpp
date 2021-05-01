#include "vec.h"
#include "lec.h"

void vectors() {
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
}

void some_pairs() {
	Pair a(1, 2);
	f(a);
	cout << "-------------" << endl;
	a.print();
}

int main() {
	// vectors();
	// some_pairs();
	lec::hello();
	return 0;
}