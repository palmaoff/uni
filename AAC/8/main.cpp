#include <iostream>
using namespace std;

int	mid_search(int *arr, int s, int e, int middle)
{
	int left = arr[middle], right = arr[middle];
	for (int i = middle; i >= s; i--)
	{
		if (arr[i] < left)
			left = arr[i];
	}
	for (int i = middle; i <= e; i++)
	{
		if (arr[i] > right)
			right = arr[i];
	}
	return (right - left);
}

int	search(int *arr, int l, int r, int &i, int &j)
{
	i = -1;
	j = -1;
	if (r - l == 1)
	{
		if (arr[l] < arr[r])
		{ i == l; j = r;}
	}
	else
	{
		search(arr, l , (r + l) / 2, i1, j1);
		search(arr, l , (r + l) / 2, (r + l) / 2, r, j2, j2);
	}

}

int main()
{
	int a[] = {5, 4, 3};
	cout << search(a, 0, 2) << endl;
	return 0;
}

/*
	Есть курс акций за последние n дней.
	Для каждого дня известна катировка акций в этот день.
	Предположим, что в какой-то день нужно купить 1000 акций и продать в другой 
	более поздний день.
	Вопрос: когда покупать и когда продавть для получения наибольшей прибыли
	(если продажа с прибылбю невозможна - сообщить об этом)
*/