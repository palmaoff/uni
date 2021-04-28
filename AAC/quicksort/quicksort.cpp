#include <iostream>
using namespace std;

void print_arr(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
	cout << endl;
}

// метод Хоара
void qs(int *arr, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = arr[(left + right) / 2];
        while (left < right)
        {
            while (arr[left] < middle) left++;
            while (arr[right] > middle) right--;
            if (left <= right)
            {
                // swap
                int tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
                left++;
                right--;
            }
        }
        print_arr(arr, 6);
        qs(arr, first, right);
        qs(arr, left, last);
    }
}

int main()
{
	int a[6] = {2, 8, 5, -1, 10, 3};

    cout << "given: \n";
	print_arr(a, 6);
    cout << endl;

	qs(a, 0, 5);

    cout << "\nresult: \n";
	print_arr(a, 6);

	return 0;
}
