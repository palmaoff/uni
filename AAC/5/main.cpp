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
		cout << a[i];
	cout << endl;
}

void qs(int *arr, int middle, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last;
        while (left <= right)
        {
            while (arr[left] < middle) left++;
            while (arr[right] > middle) right--;
            if (left <= right)
            {
				swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
        // qs(arr, first, right);
        // qs(arr, left, last);
    }
}

void solution(int *a, int *b, int n)
{

}

int main()
{
	int a[10] = {2, 3, 5, 1, 8, 10, 4, 9, 7, 6};
	int b[10] = {1, 4, 8, 5, 3, 2, 7, 6, 10, 9};

	solution(a, b, 10);
}
