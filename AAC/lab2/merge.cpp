#include "merge.h"

void copy_arr(int *a1, int *a2, int i)
{
	int j = 0;

	while (a1[j] != 0)
		j++;
	for (int k = 0; k < i; k++)
	{
		a1[j] = a2[k];
		j++;
	}
}

void	merge_arrs(int *m1, int *m2, int n)
{
	int i = 0, j = 0, k = 0;
	int arr[n * n];
	while (i < n || j < n)
	{
		if (m1[i] < m2[j])
		{
			arr[k] = m1[i];
			i++;
		}
		else
		{
			arr[k] = m2[j];
			j++;
		}
		k++;
	}
	while (i < n)
	{
		arr[k] = m1[i];
		k++;
		i++;
	}
	while (j < n)
	{
		arr[k] = m2[j];
		k++;
		j++;
	}
	// copy_arr(arr, n * n);
}

void	merge(int **arr, int *arr_new, int i, int j)
{
	return ;
}
