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
	for (int i = 1; i <= n; i++)
	{
		if (check(i))
			cout << i << "\n";
	}
	return (0);
}