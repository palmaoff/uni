#include "students.h"

int main()
{
	// если не работает русский язык
	// setlocale(LC_ALL, "Rus"); 
	Students* stud;
	int n;

	cout << "Enter number of stdents: ";

	// количество студентов
	cin >> n;
	// выделяем память для необходимого количества студентов
	stud = new Students[n];

	// считываем информацию с консоли
	read_inf(stud, n);

	// печать этой информации в файл
	print_in_file("in.txt", stud, n);

	cout << "\n-------------------------\nsorted: \n\n";

	// сортировка по среднему баллу
	sort_marks(stud, n);
	print_inf(stud, n);

	// печать средних баллов в файл
	marks_file("sort.txt", stud, n);
	// бинарный файл
	marks_bin_file("marks.bin", stud, n);

	// вывод фамилий учеников с наибольшим колличеством отличных оценок
	cout << "best grades: \n";
	best_grades(stud, n);

	// чистим массив
	delete [] stud;
	return 0;
}
