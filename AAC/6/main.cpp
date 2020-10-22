#include <iostream>
using namespace std;

int max_uni(int *a, int s, int e)
{
	int middle = (e + s) / 2;

	if (s - e == 0)
		return a[s];
	if (s - e == 1)
		return a[s] > a[e] ? a[s] : a[e];
	if (a[middle + 1] < a[middle] && a[middle - 1] < a[middle])
		return a[middle];
	else if (a[middle - 1] > a[middle])
		return max_uni(a, s, middle - 1);
	else
		return max_uni(a, middle + 1, e);
}

int main() 
{
	int max[] = {5, 4, 3};
	cout << max_uni(max, 0, 0) << endl;
	return 0;
}

// горочка в массиве
