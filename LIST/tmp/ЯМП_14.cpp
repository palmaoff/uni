// #include <Windows.h>
#include "List.h"

int main()
{
	// setlocale(LC_ALL, "Russian");
	Tlist list1=NULL;
	int vib;
	cout << "Как вы хотите ввести данные? 1- с клавиатуры, 2- с файла" << endl;
	cin >> vib;
	switch(vib) {
	case 1: {
		Init(list1);
		cout << "Введите количество узлов списка" << endl;
		int k;
		cin >> k;
		int elem;
		for (int i = 0; i < k; i++) {
			cin >> elem;
			Add_to_end(list1, elem);
		}
		break;
	}
	case 2: {
		string path;
		cout << "Введите путь к файлу" << endl; //пути input1.txt input2.txt
		cin >> path;
		ifstream fin;
		fin.open(path);
		if (!fin.is_open()) {
			cout << "Ошибка открытия файла";
			return 0;
		}
		if (fin.peek() == EOF) { 
			cout << "Файл пуст" << endl; 
			return 0;
		}
		else {
			create_as_stack(list1, fin);
		}
		fin.close();
		break;
	}
	default: { 
			  cout << "Ошибка выбора" << endl;
			  return 0;
		  }
	}
	if (empty(list1))cout << "Список пуст" << endl;
	else {
	Print(list1);
	int a = max_negative(list1);
	if (a == 0) cout << "Отрицательный чисел нет" << endl;
	else cout << "Максимальное отрицательное число  " << a << endl;
	}
	//Add_to_head(list1, 14);  //для проверки методов
	//cout << count_nodes(list1) << endl;
	//Clear(list1);
	Print(list1);
	return 0;
}
