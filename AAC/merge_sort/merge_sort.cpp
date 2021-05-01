#include <iostream>
using namespace std;

int Merge(int *A, int first, int last)
{
	int middle, start, final, j, counter;
	int *mas = new int[100];

	middle = (first + last) / 2;
	cout << middle << endl; 
	start = first;
	final = middle + 1;
	counter = 0;

	for (j = first; j <= last; j++)
		if ((start <= middle) && ((final > last) || (A[start] < A[final])))
		{
			mas[j] = A[start];
			start++;
		}
		else
		{
			mas[j] = A[final];
			final++;
			if (start <= middle)
				counter += middle - start; // count 
		}

	for (j = first; j <= last; j++)
		A[j] = mas[j];

	delete[] mas;
	return counter;
}

int	MergeSort(int *A, int first, int last)
{
	int counter;

	counter = 0;
	if (first < last)
	{
		counter += MergeSort(A, first, (first + last) / 2);
		counter += MergeSort(A, (first + last) / 2 + 1, last);
		counter += Merge(A, first, last);
	}
	return counter;
}

void print_arr(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main()
{
	int a[6] = {5, 3, 2, 6, 8, 10};
	int counter;

	print_arr(a, 6);
	counter = MergeSort(a, 0, 5);
	print_arr(a, 6);
	cout << counter << endl;

	return 0;
}
