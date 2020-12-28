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
	int r1;
	int r2;

	sum = arr[1] - arr[0];
	for (int i = 3; i < n - 2; i++)
	{
		r1 = arr[i] - arr[i - 1];
		r2 = arr[i + 1] - arr[i];
		sum += (r1 > r2) ? r2 : r1;
	}
	sum += arr[n - 1] - arr[n - 2];
	return sum;
}

int main()
{
	ifstream fin;
	int n;
	int *arr;

	fin.open("in.txt");
	fin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++)
		fin >> arr[i];
	qs(arr, 0 , n - 1);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	cout << minSum(arr, n) << endl;
	
	delete [] arr;
	return 0;
}