/*
	Объединить n отсортированных массивов в новый отсортированный массив.
*/

#include "merge.h"

void	print_arr(int *a, int count)
{
	for (int i = 0; i < count; i++)
		cout << a[i] << " ";
	cout << endl;
}

void init(int **&arr, int *&res, int i, int j)
{
	res = new int[i * j];
	arr = new int*[j];
	for (int k = 0; k < j; k++)
		arr[k] = new int[i];	
	
	for (int k = 0; k < j; k++)
		for (int n = 0; n < i; n++)
			cin >> arr[k][n];

	for (int n = 0; n < i * j; n++)
		res[n] = 0;
}

int main()
{
	int **arr, *res, n, m;

	cout << "Enter number of arrays: ";
	cin >> m;
	cout << "Enter number of elements: ";
	cin >> n;

	init(arr, res, n, m);
	res = merge_all(arr, n, 0, m - 1);
	print_arr(res, n * m);

	return 0;
}
