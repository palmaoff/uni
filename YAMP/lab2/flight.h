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
	int		setD(int d);
	int		setM(int m);
	int		setY(int y);
	bool	isLater(Date d);
	bool	isEqual(Date d);
	void	read();
	string	toString();
};

class Flight: public Date
{
	string	to;
	string	from;
public:
	Flight();
	string	getTo();
	string	getFrom();
	string	toString();
	void	setTo(string t);
	void	setFrom(string f);
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
	void 	print();
	void 	print(Date d);
	void 	print(int d);
	int 	read_from_file(string file);
	void 	print_in_file(string file);
	Node*	find(int i);
	void	sort_date();
	void	test();
};

#endif