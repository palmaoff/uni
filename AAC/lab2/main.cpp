#include "merge.h"

void	print_arr(int *a, int count)
{
	for (int i = 0; i < count; i++)
		cout << a[i] << " ";
	cout << endl;
}

void	print_arrs(int **a, int i, int j)
{
	for (int k = 0; k < i; k++)
		print_arr(a[k], j);
}

void init(int **arr, int *arr_new, int i, int j)
{
	arr_new = new int[i * j];
	arr = new int*[i];
	for (int k = 0; k < i; k++)
		arr[k] = new int[j];	
	
	for (int k = 0; k < i; k++)
	{
		for (int n = 0; n < j; n++)
			arr[k][n] = 1;
	}
	for (int n = 0; n < j * i; n++)
			arr_new[n] = 1;	
}

int main()
{
	int **arr, *arr_new;
	init(arr, arr_new, 3, 5);
	print_arr(arr_new, 3);
	print_arrs(arr, 3, 5);
	return 0;
}
