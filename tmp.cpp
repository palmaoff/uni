#include <iostream>
using namespace std;

class A
{
	int a;
	int b;
public:
	A(int _a = 10, int _b = 20) : a(_a), b(_b) {}
};

class B: public A 
{
	int c;
public:
	B(int _c) : c(_c) {}
};

int main()
{
	A obj(2, 3);
	B objB(5);
	return 0;
}
