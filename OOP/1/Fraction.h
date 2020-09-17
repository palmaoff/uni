#include <iostream>
#include <string.h>
using namespace std;

class Fraction {
	long int n;
	short int d;
	void	Norm(Fraction &a) {
		int i = 2;
		while (i <= a.n && i <= a.d) {
			if (a.n % i == 0 && a.d % i == 0) {
				a.n /= i;
				a.d /= i;
				i--; 
			}
			i++;
		}
	}
	public:
	Fraction(): n(0), d(1) {}
	Fraction(long int n): d(1) { this->n = n; }
	Fraction(long int N, short int D): n(N), d(D) {}
	~Fraction() {
		cout << "destructor" << endl;
	}
	void set(long int n, short int d) {
		if (d < 1) {
			cout << "incorrect input" << endl;
			return ;
		}
		this->n = n;
		this->d = d;
		Norm(*this);
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
	Fraction sum(Fraction &a) {
		Fraction sum;

		sum.d = a.d * d;
		sum.n = a.n * d + n * a.d;
		Norm(sum);
		return sum;
	}
	Fraction sub(Fraction &a) {
		Fraction sub;

		sub.d = a.d * d;
		sub.n = n * a.d - a.n * d;
		Norm(sub);
		return sub;
	}
	Fraction mult(Fraction &a) {
		Fraction m;
		
		m.d = a.d * d;
		m.n = a.n * n;
		Norm(m);
		return m;
	}
	bool cmp(Fraction &a) {
		if (d == a.d)
			return (n > a.n);
		return (n * a.d > a.n * d);
	}
	void print() {
		cout << n << '/' << d << endl;
	}
	string toString() {
		if (n == 0 || d == 1)
			return to_string(n);
		return to_string(n) + "/" + to_string(d);
	}
};
