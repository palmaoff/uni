#include <iostream>
using namespace std;

class Fraction {
	int n;
	size_t d;
	Fraction Norm(Fraction a) {
		for (int i = 2; i < a.n || i < a.d; i++) {
			if (a.n % i == 0 && a.d % i == 0) {
				a.n /= i;
				a.d /= i; 
			}
		}
		return a;
	}
	public:
	Fraction() {
		n = 0;
		d = 1;
	}
	int getN() {
		return (n);
	}
	int getD() {
		return (d);
	}
	void print() {
		cout << n << '/' << d << endl;
	}
	void set(int n1, int d1) {
		n = n1;
		d = d1;
	}
	Fraction sum(Fraction a) {
		Fraction sum;
		sum.d = a.d * d;
		sum.n = a.n * d + n * a.d;
		return Norm(sum);
	}
	Fraction sub(Fraction a) {
		Fraction sub;
		sub.d = a.d * d;
		sub.n = n * a.d - a.n * d;
		return Norm(sub);
	}
	Fraction mult(Fraction a) {
		Fraction m;
		m.d = a.d * d;
		m.n = a.n * n;
		return (m);
	}
	bool cmp(Fraction a) {
		if (d == a.d)
			return (n > a.n);
		return (n * a.d > a.n * d);
	}
};
