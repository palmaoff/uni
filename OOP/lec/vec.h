#include <iostream>
using namespace std;

class vec {
	double x, y, z;
	const int k = 0;
	public:
	vec():
		x(0), z(0), y(0)
	{}
	vec(double a, double b, double c);
	double scalar(vec a) {
		return (x * a.x + y * a.y + z * a.z);
	}
	void print() {
		cout << x << ' ' << y << ' ' << z << endl;
	}
};

vec::vec(double a, double b, double c) {
	x = a;
	y = b;
	z = c;
}

// encapsulation - объединение данных и методов их обработки
// polymorphism - многообразие видов (перегрузка)
