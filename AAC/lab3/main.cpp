/*
	Имеется набор строк, каждая из которых представляет собой натуральное число.
	Только вместо цифр строки содержат буквы от ‘A’ до ‘J’. Каждая буква
	обозначаетодну цифру, а каждая цифра кодируется только одной буквой. Ни
	одно число не начинается нулем. В задаче требуется найти наибольшее
	возможное значение суммы всех чисел.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Pair
{
	char l;
	unsigned long int k;
	bool canzero;
};

unsigned long int ft_pow(unsigned long int x, unsigned int n)
{
	int result = x;
	if (n == 0)
		result = 1;
	for (int i = 1; i < n; i++)
		result *= x;
	return result;
}

void swap(Pair &a, Pair &b)
{
	Pair tmp = a;

	a = b;
	b = tmp;
}

void qs(Pair s_arr[], int first, int last)
{
	if (first < last)
	{
		int left = first, right = last, middle = s_arr[(left + right) / 2].k;
		while (left <= right)
		{
			while (s_arr[left].k < middle)
				left++;
			while (s_arr[right].k > middle)
				right--;
			if (left <= right)
			{
				swap(s_arr[left], s_arr[right]);
				left++;
				right--;
			}
		}
		qs(s_arr, first, right);
		qs(s_arr, left, last);
	}
}

long long int maxSum(string *str, int n)
{
	Pair arr[10];
	char c = 'A'; // 65

	// init array
	for (int i = 0; i < 10; i++)
	{
		arr[i].k = 0;
		arr[i].l = c;
		arr[i].canzero = 1;
		c++;
	}

	// perform k
	for (int i = 0; i < n; i++)
	{
		int l = str[i].length() - 1;
		for (int j = 0; j <= l; j++)
		{
			arr[(int)str[i][j] - 65].k += ft_pow(10, l - j);
			if (j == 0)
				arr[(int)str[i][j] - 65].canzero = 0;
		}
	}

	// sorting array
	qs(arr, 0, 9);

	// if 0 is first
	if (arr[0].canzero == 0)
	{
		int i = 0;
		while (arr[i].canzero == 0)
			i++;
		swap(arr[0], arr[i]);
	}

	// string with digits
	for (int k = 0; k < 10; k++)
		for (int i = 0; i < n; i++)
		{
			int l = str[i].length();
			for (int j = 0; j < l; j++)
			{
				if (arr[k].l == str[i][j])
					str[i][j] = k + '0';
			}
		}

	// making sum
	long long int sum = 0;
	for (int i = 0; i < n; i++)
		sum += stoll(str[i]);
	return sum;
}

int main()
{
	ifstream fin;
	string buff;
	int n;
	string *arr;

	fin.open("in.txt");

	while (getline(fin, buff))
	{
		n = stoi(buff);
		arr = new string[n];
		for (int i = 0; i < n; i++)
		{
			getline(fin, buff);
			arr[i] = buff;
		}
		cout << maxSum(arr, n) << endl;
		delete[] arr;
	}
	return 0;
}
