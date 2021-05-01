/*
	Напишите программу, которая для двух вершин дерева определяет,
	является ли одна из них предком другой
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Marker
{
	int d;
	int f;
};

void markers(int* arr, Marker* &m, int n, int r, int& i)
{
	if (m[r].d != 0 && m[r].f != 0)
		return ;
	else if (m[r].d == 0 && m[r].f == 0)
	{
		m[r].d = i;
		for (int j = 0; j < n; j++)
		{
			if (arr[j] == r + 1)
				markers(arr, m, n, j, ++i);
		}
		i++;
		m[r].f = i;
	}
}

int main()
{
	ifstream fin;
	string buff;
	Marker* m;
	int* arr;
	int j = 1;
	int r = 0;
	int n;

	fin.open("in.txt");

	fin >> n;

	// allocate memory
	arr = new int[n];
	m = new Marker[n];

	// init arrays
	for (int i = 0; i < n; i++)
	{
		fin >> arr[i];
		m[i].d = 0;
		m[i].f = 0;
	}

	// find the first node
	while (arr[r] != 0)
		r++;

	// create arrs with markers
	markers(arr, m, n, r, j);

	for (int i = 0; i < n; i++)
		cout << m[i].d << " ";
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << m[i].f << " ";
	cout << endl;

	// intput nodes
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> j;
		fin >> r;

		// check if one is parent of anouther
		cout << j << " " << r << ": ";
		if (m[j - 1].d < m[r - 1].d && m[j - 1].f > m[r - 1].f)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}

	// delete arrays
	delete[] arr;
	delete[] m;

	return 0;
}