#include <iostream>

using namespace std;

void InsertSort(int *mas, int n) {
	for (int i = 0; i < n - 1; i++) {
		int key = i + 1, tmp = mas[key];
		for (int j = i + 1; j > 0; j--) {
			if (tmp < mas[j - 1]) {
				mas[j] = mas[j - 1];
				key = j - 1;
			}
		}
		mas[key] = tmp;
	}
	
	// cout << endl << "Результирующий массив: ";
	// for (int i = 0; i < n; i++)
	// 	cout << mas[i] << " ";
	// cout << endl;
}

/*
int main() {
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Количество элементов в массиве > ";
	cin >> n;

	int *mas = new int[n];
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " элемент > ";
		cin >> mas[i];
	}
	InsertSort(mas, n); //вызов функции
	delete[] mas;
	return 0;
}
*/
