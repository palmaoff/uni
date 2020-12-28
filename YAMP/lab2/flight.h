#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Date
{
	int 	day;
	int 	month;
	int 	year;
public:
	Date();
	int		getD();
	int		getM();
	int		getY();
	void	setD(int d);
	void	setM(int m);
	void	setY(int y);
	void	setDate(Date d); 
	bool	isLater(Date d);
	bool	isEqual(Date d);
	bool	checkDate();
	int		read(const char *buff);
	int		read();
	string	toString();
};

class Flight
{
	string	to;
	string	from;
	Date	leave;
	Date	arrive;

public:
	Flight();
	string	getTo();
	string	getFrom();
	string	toString();
	void	setTo(string t);
	void	setFrom(string f);
	int		setArrive(const char *buff);
	int		setLeave(const char *buff);
	void	setArrive(Date d);
	void	setLeave(Date d);
	Date	getArrive();
	Date	getLeave();
};

struct Node
{
	int		id;
	Flight	f;
	Node*	next;
	Node*	prev;
};

class list
{
	Node	*head;

	void	swap_nodes(Node* &a, Node* &b);
	void	near_swap(Node* n1, Node* n2);
	void 	swap(Node* n1, Node* n2);
public:
	// constructor
	list();

	// base functions
	void	init();
	bool	is_empty();

	// add functions
	Node*	add_back(int data);
	Node*	add_front(int data);

	// delete functions
	void 	del();
	void 	del_back();
	void 	del_front();
	void 	del(Node *&node);

	// additional functions
	int		count();
	int		countFrom(string str);
	int		countTo(string str);
	void 	print();
	void 	print(Date d);
	void 	print(int d);
	int 	read_from_file(string file);
	void 	print_in_file(string file);
	Node*	find(int i);
	void	sort_date();
	void	test();
	bool	edit(int id);
};

int		nextCharacter(const char *buff, int i);
bool	isLeap(int y);

#endif