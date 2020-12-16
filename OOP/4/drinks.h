#ifndef DRINKS_H
#define DRINKS_H

#include <iostream>
#include <string>
using namespace std;

class Drink
{
	string	type;
	int		temp;
public:
	Drink();

};

class Tea : public Drink // 1
{

};

class PocketTea : public Drink // 2
{

};

class Coffee : public Drink // 3
{

};

class MulledWine : public Drink // 4
{

};

class  : public Drink // 5
{

};

#endif