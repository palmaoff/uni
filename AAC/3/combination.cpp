#include "iostream"
using namespace std;

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void next_comb(int *a, int size, int k)
{
	for (int i = size - 1; i >= 0; i--)
	{
		if (a[i] < k - size + i + 1)
		{
			++a[i];
			for (int j = i + 1; j < size; j++)
				a[j] = a[j - 1] + 1;
		}
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
	int *a = new int[5];
	for (int i = 0; i < 5; i++)
	{
		a[i] = i + 1;
	}
	print_arr(a, 5);
	while (!(a[0] == 3 && a[1] == 4 && a[2] == 5 && a[3] == 6 && a[4] == 7))
	{
		next_comb(a, 5, 7);
		print_arr(a, 5);
	}
	return 0;
}

// C из 7 по 5
// 1 2 3 4 5 6 7
// 1 2 3 4 5 begin
// 3 4 5 6 7 end
