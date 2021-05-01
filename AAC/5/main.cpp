/*	
	гайки и болты разного размера
	парные гайки и болты
	сравнивать только болт с гайкой
	сопоставить гайки и болты
*/

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_arr(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void qs_2_arr(int *a, int *b, int first, int last, int middle = 0)
{
    if (first < last)
    {
        int left = first, right = last, base = b[middle];
        while (left <= right)
        {
            while (a[left] < base) left++;
            while (a[right] > base) right--;
            if (left <= right)
            {
				swap(a[left], a[right]);
                left++;
                right--;
            }
        }
		// cout << left << endl;
        // qs_2_arr(b, a, first, last, right);
        // qs_2_arr(a, b, first, right, first);
        // qs_2_arr(a, b, left, last, left);
    }
}

int main()
{
	int a[10] = {2, 3, 5, 1, 8, 10, 4, 9, 7, 6};
	int b[10] = {5, 4, 8, 1, 3, 2, 7, 6, 10, 9};

	// print init arrays
	print_arr(a, 10);
	print_arr(b, 10);
	cout << endl;

	// doing sort
	qs_2_arr(a, b, 0, 9);
	// qs_2_arr(b, a, 0, 9, 0);

	// print result
	print_arr(a, 10);
	print_arr(b, 10);

	return 0;
}
