#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

void print_arr(int *a, int n);
void qs(int *arr, int first, int last);
void InsertSort(int *mas, int n);

void print_arr_file(int *a, int n, string file)
{
	ofstream fout;
	int newLine = 0;

	fout.open(file);
	for (int i = 0; i < n; i++) {
		fout << a[i];
		newLine++;
		(newLine % 25 == 0) ? fout << endl : fout << " ";
	}
	fout << endl;
}

int input(int **arr) {
	int n;
	ifstream fin;

	// open & read
	fin.open("input.txt");
	fin >> n;
	*arr = new int[n];
	for (int i = 0; i < n; i++)
		fin >> *((*arr) + i);

	fin.close();
	return n;
}

void rand_arr(int n)
{
	ofstream fout;

	fout.open("input.txt");
	fout << n << endl;
	for (int i = 0; i < n; i++) {
		fout << rand() << " ";
	}
}

int main() {
	int *arr = NULL, n = 0;

	cout << "Enter number of digits: ";

	// input & generation arr
	int a;
	cin >> a;
	rand_arr(a);
	n = input(&arr); 

	// QS
	cout << "Number of elements: " << n << endl;
	clock_t start = clock();
	qs(arr, 0, n - 1);
	clock_t stop = clock();
	double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	cout << "Time for QS elapsed in ms: " << elapsed << endl;
	print_arr_file(arr, n, "out_QS.txt");
	delete [] arr;

	// IS
	input(&arr);
	start = clock();
	InsertSort(arr, n);
	stop = clock();
	elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	cout << "Time for IS elapsed in ms: " << elapsed << endl;
	print_arr_file(arr, n, "out_IS.txt");
	delete [] arr;

	return 0;
}
