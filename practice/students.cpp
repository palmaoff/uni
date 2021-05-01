#include "students.h"

// чтение и запись в структуру
void read_inf(Students *stud, int n)
{
	cout << "Enter data: \n";

	for (int i = 0; i < n; i++)
	{
		cin >> stud[i].name;
		cin >> stud[i].lastName;
		stud[i].score = 0;
		for (int j = 0; j < 5; j++)
		{
			cin >> stud[i].mark[j];
			stud[i].score += stud[i].mark[j];
		}
		stud[i].score /= 5;
	}
}

// вывод в консоль
void print_inf(Students *stud, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << stud[i].name << " ";
		cout << stud[i].lastName << " ";
		for (int j = 0; j < 5; j++)
			cout << stud[i].mark[j] << " ";
		cout << "\t" << stud[i].score;
		cout << endl;
	}
}

// вывод в файл
void print_in_file(string file, Students *stud, int n)
{
	ofstream fout;

	fout.open(file);
	for (int i = 0; i < n; i++)
	{
		fout << stud[i].name << " ";
		fout << stud[i].lastName << " ";
		for (int j = 0; j < 5; j++)
			fout << stud[i].mark[j] << " ";
		fout << endl;
	}
	fout.close();
}

// сортировка по среднему баллу
void sort_marks(Students *stud, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (stud[i].score > stud[j].score)
			{
				// swap
				Students tmp = stud[i];
				stud[i] = stud[j];
				stud[j] = tmp;
			}
		}
}

// вывод средних баллов в файл
void marks_file(string file, Students *stud, int n)
{
	ofstream fout;

	fout.open(file);
	for (int i = 0; i < n; i++)
	{
		fout << stud[i].name << " ";
		fout << stud[i].lastName << " ";
		fout << stud[i].score << " ";
		fout << endl;
	}
	fout.close();
}

// вывод средних баллов в бинарный файл
void marks_bin_file(string file, Students *stud, int n)
{
	ofstream fout(file, ios::binary);

	for (int i = 0; i < n; i++)
	{
		fout.write((char *)stud[i].name.c_str(), stud[0].name.length() + 1);
		fout.write((char *)stud[i].name.c_str(), stud[0].lastName.length() + 1);
		fout.write((char *)&stud[i].score, sizeof(stud[i].score));
	}

	fout.close();
}

// вывод учеников с наибольшим колличеством средних баллов
void best_grades(Students *stud, int n)
{
	size_t i = n - 1, max = 0;

	// считаем количество оценок 5 у последнего ученика
	for (int k = 0; k < 5; k++)
		if (stud[i].mark[k] == 5)
			max++;

	// смотрим с конца есть ли ученики с таким же количеством
	while (max != -1)
	{
		size_t cur = 0;
		for (int k = 0; k < 5; k++)
			if (stud[i].mark[k] == 5)
				cur++;
		if (cur == max)
			cout << stud[i].lastName << endl;
		else
			max = -1;
		i--;
	}
}
