#include <iostream>
#include <string.h>
using namespace std;

class Fraction {
	long int n;
	short int d;
	Fraction Norm(Fraction a) {
		for (int i = 2; i < (a.n / 2) || i < (a.d / 2); i++) {
			if (a.n % i == 0 && a.d % i == 0) {
				a.n /= i;
				a.d /= i; 
			}
		}
		return a;
	}
	public:
	Fraction(): n(0), d(1) {}
	Fraction(long int n): d(1) { this->n = n; }
	Fraction(long int n, short int d) {
		this->n = n;
		this->d = d;
	}
	void set(long int n, short int d) {
		if (d < 1) {
			cout << "incorrect input" << endl;
			return ;
		}
		this->n = n;
		this->d = d;
		*this = Norm(*this);
	}
	Fraction get() {
		Fraction g;

		g.n = n;
		g.d = d;
		return g;
	}
	int getN() {
		return n;
	}
	int getD() {
		return d;
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
		return Norm(m);
	}
	bool cmp(Fraction a) {
		if (d == a.d)
			return (n > a.n);
		return (n * a.d > a.n * d);
	}
	void print() {
		cout << n << '/' << d << endl;
	}
	string toString() {
		return "itoaaa";
	}
};
