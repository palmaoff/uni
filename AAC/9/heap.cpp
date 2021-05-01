#include <iostream>

void	swap(int &a, int &b)
{
	int tmp = a;

	a = b;
	b = tmp;
}

void	heap_rebuild(int *buff, int i, int size)
{
	if (2 * i < size && buff[i] > buff[2 * i])
	{
		swap(buff[i], buff[2 * i]);
		heap_rebuild(buff, 2* i, size);
	}
	else if (2 * i + 1 < size && buff[i] > buff[2 * i + 1])
	{
		swap(buff[i], buff[2 * i]);
		heap_rebuild(buff, 2 * i + 1, size);
	}
}

int main()
{
	return 0;
}
