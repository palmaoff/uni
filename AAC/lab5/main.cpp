/*
	На прямой доске вбиты гвозди. Любые два гвоздя можно соединить ниткой.
	Требуется соединить некоторые пары гвоздей ниткой так, чтобы к каждому
	гвоздю была привязана хотя бы одна нитка, а суммарная длина всех нитей
	была бы минимальна.
*/

#include <iostream>
#include <fstream>

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

int minSum(int *arr, int n)
{
	int sum;
	int* brr;

	brr = new int[n];
	if (n < 2)
		return 0;
	brr[n - 1] = 10000;
	brr[n - 2] = arr[n - 1] - arr[n - 2];
	for (int i = n - 3; i >= 0; i--)
	{
		brr[i] = (brr[i + 1] > brr[i + 2]) ? brr[i + 2] : brr[i + 1];
		brr[i] += arr[i + 1] - arr[i];
	}

	for (int i = 0; i < n; i++)
		cout << brr[i] << " ";
	cout << endl;

	sum = brr[0];
	delete [] brr;
	return sum;
}

int main()
{
	ifstream fin;
	int n;
	int *arr;

	// open & read
	fin.open("in.txt");
	fin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++)
		fin >> arr[i];

	// sort
	qs(arr, 0 , n - 1);

	// print
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	// sum
	cout << minSum(arr, n) << endl;

	// clean memory	
	delete [] arr;

	return 0;
}