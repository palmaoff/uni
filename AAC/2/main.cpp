#include "iostream"
using namespace std;

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void get_next(int *a, int n)
{
	int i = n - 2;
	while (a[i] > a[i + 1])
		i--;
	int j = n - 1;
	while (a[j] < a[i])
		j--;
	swap(&a[i], &a[j]);
	int l = i + 1, r = n - 1; // сортируем оставшуюся часть последовательности
	while (l < r)
	{
		swap(a[l], a[r]);
		r--;
		l++;
	}
}

void print_arr(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i];
	cout << endl;
}

int main()
{
	int *a = new int[4];
	for (int i = 0; i < 4; i++)
	{
		a[i] = i + 1;
	}
	print_arr(a, 4);
	while (!(a[0] == 4 && a[1] == 3 && a[2] == 2 && a[3] == 1))
	{
		get_next(a, 4);
		print_arr(a, 4);
	}
	return 0;
}

// 1 2 3 4 - перестановки
