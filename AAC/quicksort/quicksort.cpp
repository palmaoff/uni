#include <iostream>
using namespace std;

void qs(int *s_arr, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = s_arr[(left + right) / 2];
        while (left <= right)
        {
            while (s_arr[left] < middle) left++;
            while (s_arr[right] > middle) right--;
            if (left <= right)
            {
                int tmp = s_arr[left];
                s_arr[left] = s_arr[right];
                s_arr[right] = tmp;
                left++;
                right--;
            }
        }
        qs(s_arr, first, right);
        qs(s_arr, left, last);
    }
}

void print_arr(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main()
{
	int a[6] = {2, 3, 5, -1, 8, 10};
	print_arr(a, 6);
	qs(a, 0, 5);
	print_arr(a, 6);
	return 0;
}

