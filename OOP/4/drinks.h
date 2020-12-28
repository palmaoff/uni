#ifndef DRINKS_H
#define DRINKS_H

#include <iostream>
#include <string>
using namespace std;

class Drink
{
	int currtemp;
	string taste;

	virtual void TasteGood();
public:
	Drink();
	Drink(int temp);
	void set(int temp);
	void setTaste(string str);
	string getTaste();
	int getTemp();
};

class Tea : public Drink // 1
{
	void	TasteGood();
};

class PocketTea : public Drink // 2
{
	void	TasteGood();
};

class Coffee : public Drink // 3
{
	void	TasteGood();
};

class MulledWine : public Drink // 4
{
	void	TasteGood();
};

class OrangeJuice : public Drink // 5
{
	void	TasteGood();
};

void f_OrangeJuice();
void f_MulledWine();
void f_Coffee();
void f_PocketTea();
void f_Tea();

#endif