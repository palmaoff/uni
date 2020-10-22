#include <iostream>
using namespace std;

int max_middle(int *a, int s, int e, int middle)
{
	int left = 0, right = 0, tmp = middle;

	while (tmp >= s)
	{
		if (left  < left + a[tmp])
			left += a[tmp];
		tmp--;
	}
	while (tmp >= s)
	{
		if (left  < left + a[tmp])
			left += a[tmp];
		tmp--;
	}
}

int	max_sum(int *a, int s, int e)
{
	int s1, s2, s3;
	int middle = (e + s) / 2;
	s1 = max_sum(a, s, middle);
	s2 = max_sum(a, s, middle);
	s3 = max_middle(a, s, e, middle);
}

int main() 
{
	int a[] = {5, 4, 3};
	cout << max_sum(a, 0, 2) << endl;
	return 0;
}

// подмассив с наибольшей суммой
