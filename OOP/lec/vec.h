#include <iostream>
using namespace std;

class vec {
	double x, y, z;
	public:
	vec():
		x(0), y(0), z(0)
	{}
	vec(double a, double b, double c);
	double scalar(vec a) {
		return (x * a.x + y * a.y + z * a.z);
	}
	void print() {
		cout << x << ' ' << y << ' ' << z << endl;
	}
	vec operator+ (vec r) {
		vec tmp;

		tmp.x = x + r.x;
		tmp.y = y + r.y;
		tmp.z = z + r.z;
		return tmp;
	}
	void operator++() {
		x++;
		y++;
		z++;
	} // a++
	void operator++(int) {
		++x;
		++y;
		++z;
	} // ++a
};

vec::vec(double a, double b, double c):
	x(a), y(b), z(c) 
{}

// encapsulation - объединение данных и методов их обработки
// polymorphism - многообразие видов (перегрузка)
