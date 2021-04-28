#ifndef STUDENTS
#define STUDENTS

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Students
{
	string name;
	string lastName;
	int mark[5];
	float score;
};

void read_inf(Students *stud, int n);
void print_inf(Students *stud, int n);
void print_in_file(string file, Students *stud, int n);
void sort_marks(Students *stud, int n);
void marks_file(string file, Students *stud, int n);
void marks_bin_file(string file, Students *stud, int n);
void best_grades(Students *stud, int n);

#endif
