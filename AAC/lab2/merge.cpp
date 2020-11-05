#include "merge.h"

void	Merge(int *A, int *B, int *&res, int a, int b)
{
	int start, final, i;

	start = 0;
	final = 0;
	int arr[100];

	for (i = 0; i < a + b; i++)
		if ((start < a) && ((A[start] < B[final]) || (final >= b)))
		{
			arr[i] = A[start];
			start++;
		}
		else if (final < b)
		{
			arr[i] = B[final];
			final++;
		}
	for (i = 0; i < a + b; i++)
		res[i] = arr[i];
}

int		*merge_all(int **arr, int n, int start, int end)
{
	int *result = new int[n * (end - start + 1)];
	int *m1, *m2;

	if (end - start > 1)
	{
		m1 = merge_all(arr, n, start, (end - start) / 2);
		m2 = merge_all(arr, n, (end - start) / 2 + 1, end);
		Merge(m1, m2, result, n * ((end - start) / 2 - start + 1),
			n * (end - ((end - start) / 2 + 1) + 1));
		delete [] m1;
		delete [] m2;
	}
	else if (end - start == 0)
		for (int i = 0; i < n; i++)
			result[i] = arr[start][i];
	else if (end - start == 1)
		Merge(arr[start], arr[end], result, n, n);
	return result;
}
