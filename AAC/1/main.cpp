#include <iostream>
#include <math.h>
using namespace std;

int n_len(int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

bool is_last(int *m, n) {
	int i = 0;

	while (i < n) {
		if (m[i] != 9)
			return FALSE;
	}
	return TRUE;
}

int check(int n)
{
	int s = 0;
	int i;
	int copy = n;

	i = n_len(n);
	while (n > 0)
	{
		s += pow(n % 10, i);
		n /= 10;
	}
	return (s == copy) ? 1 : 0;
}

int main() {
	int n;
	cout << "Enter n: ";
	cin >> n;
	int *m = new int[n];
	delete [] m;
	return (0);
}
