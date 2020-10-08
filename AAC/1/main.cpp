#include <iostream>
#include "armstrong.h"
#include <math.h>
using namespace std;

int number_of_digits(int *m, int n)
{
	int i = 0;

	while (i < n && m[i] == 0)
		i++;
	return i;
}

int increment(int *m, int n)
{
	int i = n - 1;

	while (i > 0 && m[i] == 9)
		i--;
	if (m[i] != 9)
		m[i]++;
	else
		return 0;
	for (int j = i + 1; j < n; j++)
		m[j] = 0;
	return 1;
}

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

int arr_digit(int *m, int n)
{
	int d = 0;

	for (int i = 0; i < n; i++)
		d = d * 10 + m[i];
	return d;
}

void	arr_arm(int *m, int n, int sum)
{
	int *c = new int[n];
	int d = arr_digit(m, n);

	for (int i = 0; i < n; i++)
		c[i] = m[i];
	while (!check(d))
	{
		get_next(c, n);
		print_arr(c, n);
		d = arr_digit(c, n);
	}
	cout << d << endl;
	// print_arr(m, n);
	delete [] c;
}

int check_arm(int *m, int n, int s)
{
	int sum = 0;

	for (int i = n - 1; i >= s; i--)
		sum += pow(m[i], s);
	if (arr_digit(m, n) == 2 && sum == 2)
		cout << "yes";
	if (sum == arr_digit(m, n))
		arr_arm(m, n, sum);
	return 1;
}

int main()
{
	int n;
	int *m;

	cout << "Enter number of digits: ";
	cin >> n;
	m = new int[n];

	for (int i = 0; i < n; i++)
		m[i] = 0;
	while ((increment(m, n)) != 0)
		check_arm(m, n, number_of_digits(m, n));
	delete[] m;
	return (0);
}
